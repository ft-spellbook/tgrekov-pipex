/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subspec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:52:45 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/26 10:29:42 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "subspec.h"
#include "../utils/utils.h"
#include "../../../../libft.h"

void	init_subspec(t_subspec *subspec)
{
	subspec->left_justify = 0;
	subspec->forced_sign = 0;
	subspec->force_decimal = 0;
	subspec->pad_str = "          ";
	subspec->min_width = 0;
	subspec->precision = -1;
	subspec->lenmod = none;
}

static void	parse_lenmod(const char **format, t_subspec *subspec)
{
	if (**format == 'h' && (*format)++)
	{
		subspec->lenmod = h;
		if (**format == 'h' && (*format)++)
			subspec->lenmod = hh;
	}
	else if (**format == 'l' && (*format)++)
	{
		subspec->lenmod = l;
		if (**format == 'l' && (*format)++)
			subspec->lenmod = ll;
	}
	else if (**format == 'j' && (*format)++)
		subspec->lenmod = j;
	else if (**format == 'z' && (*format)++)
		subspec->lenmod = z;
	else if (**format == 't' && (*format)++)
		subspec->lenmod = t;
}

static int	subspec_parse_width_or_precision(const char **format, va_list args)
{
	int	res;

	if (**format == '*')
	{
		(*format)++;
		return (va_arg(args, int));
	}
	res = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	return (res);
}

void	parse_subspec(const char **format, t_subspec *subspec, va_list args)
{
	while (**format && ft_strchr("-+ #0_", **format))
	{
		if (**format == '-')
			subspec->left_justify = 1;
		else if (**format == '+')
			subspec->forced_sign = "+";
		else if (**format == ' ')
			subspec->forced_sign = " ";
		else if (**format == '#')
			subspec->force_decimal = 1;
		else if (**format == '0' && !subspec->left_justify)
			subspec->pad_str = "0000000000";
		else if (**format == '_')
			subspec->pad_str = va_arg(args, char *);
		(*format)++;
	}
	if (**format == '*' || ft_isdigit(**format))
		subspec->min_width = subspec_parse_width_or_precision(format, args);
	if (**format == '.')
	{
		(*format)++;
		subspec->precision = subspec_parse_width_or_precision(format, args);
	}
	parse_lenmod(format, subspec);
}

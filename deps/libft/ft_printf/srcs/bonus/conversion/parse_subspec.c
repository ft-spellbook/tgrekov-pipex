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

/**
 * @file srcs/bonus/conversion/parse_subspec.c
 * @dontinclude srcs/bonus/conversion/parse_subspec.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include "subspec.h"
#include "../utils/utils.h"
#include "../../../../libft.h"

/**
 * @brief Sets initial values for a @ref s_subspec that are not always set
 * elsewhere.
 * 
 * @param[in, out] subspec 
 */
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

/**
 * @brief Parse the @ref e_lenmod"length modifier" for the sequence.
 * 
 * @param[in, out] format 
 * @param[in, out] subspec 
 */
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

/**
 * @brief Parse inline or variable argument width or precision.
 * 
 * @param[in, out] format 
 * @param[in, out] args 
 * @retval int Parsed value for width or precision.
 */
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

/**
 * @brief Parse @ref s_subspec"flags, width, precision, and length".
 * 
 * @param[in, out] format 
 * @param[in, out] subspec 
 * @param[in, out] args 
 */
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

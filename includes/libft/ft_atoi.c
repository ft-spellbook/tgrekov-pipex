/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:12:00 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/16 08:55:47 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 * @dontinclude ft_atoi.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

/**
 * @brief Converts ASCII string @p str to integer representation
 * 
 * Converts the initial numerical portion of the
 * string at pointer @p str to int representation.
 * 
 * Numerical portion may be preceded by a singular
 * optional + or - sign.
 * 
 * @param[in] str Null-terminated string containing integer
 * @retval int Result of conversion, unless the value (handled as a long during
 * conversion), would overflow or underflow, in which case it returns
 * @ref FT_LONG_MAX or <tt>@ref FT_LONG_MAX - 1</tt>, respectively.
 */
int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nbr = 0;
	while (ft_isdigit(*str))
	{
		if (nbr > FT_LONG_MAX / 10 || (nbr == FT_LONG_MAX / 10 && *str > '7'))
		{
			if (sign == 1)
				return ((int) FT_LONG_MAX);
			return ((int) -FT_LONG_MAX - 1L);
		}
		nbr = nbr * 10 + (*(str++) - '0');
	}
	return (nbr * sign);
}

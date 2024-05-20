/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:57:54 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:12:57 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_length(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*edge_case(int n)
{
	if (!n)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	int		len;
	char	negative;
	char	*str;

	if (!n || n == -2147483648)
		return (edge_case(n));
	negative = 0;
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	len = int_length(n);
	str = ft_calloc(negative + len + 1, 1);
	if (!str)
		return (0);
	if (negative)
		str[0] = '-';
	while (n)
	{
		str[negative + len-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

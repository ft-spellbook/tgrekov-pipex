/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:54:37 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:12:09 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*s2;

	if (!s)
		return (0);
	len = ft_strlen(s);
	s2 = ft_calloc(len + 1, 1);
	if (!s2)
		return (0);
	while (len--)
		s2[len] = f(len, s[len]);
	return (s2);
}

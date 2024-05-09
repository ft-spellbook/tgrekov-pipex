/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:35:17 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:54:14 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s2_len;
	char	*s2;

	if (!s)
		return (0);
	s2_len = ft_strlen(s);
	if (s2_len < start)
		return (ft_calloc(1, 1));
	s2_len = s2_len - start;
	if (s2_len > len)
		s2_len = len;
	s2 = malloc(s2_len + 1);
	if (!s2)
		return (0);
	ft_strlcpy(s2, s + start, s2_len + 1);
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:00:51 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:54:21 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtrim.c
 * @dontinclude ft_strtrim.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Allocates and returns a copy of @p s1 with any
 * successive characters found in string @p set removed
 * from the start and end
 * 
 * @param[in] s1 Null-terminated string to trim
 * @param[in] set Null-terminated string containing characters to trim off @p s1
 * @retval char* Pointer to allocated trimmed string
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s2;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	s2 = malloc(end - start + 2);
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1 + start, end - start + 2);
	return (s2);
}

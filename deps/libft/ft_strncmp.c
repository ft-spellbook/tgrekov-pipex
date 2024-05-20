/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:25:34 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:52:51 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strncmp.c
 * @dontinclude ft_strncmp.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Compare up to @p n characters of string @p s1 with string @p s2
 * 
 * @param[in] s1 Optionally null-terminated string
 * @param[in] s2 Optionally null-terminated string
 * @param[in] n Maximum number of characters to compare
 * @retval int Result of subtracting the differing
 * character of @p s2 from that of @p s1.  
 * If no difference was found in @p n characters, or before the strings were
 * terminated, returns @p 0.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

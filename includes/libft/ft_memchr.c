/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:31:16 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:46:42 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memchr.c
 * @dontinclude ft_memchr.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Finds first occurence of @p c in byte string at @p s within @p n bytes
 * 
 * Check is done as <tt>unsigned char</tt>
 * 
 * @param[in] s Byte string haystack to search
 * @param[in] c int needle to find
 * @param[in] n Number of bytes to check
 * @retval void* Pointer to first occurence of needle @p c in haystack @p s.  
 * @p NULL if none is found within @p n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

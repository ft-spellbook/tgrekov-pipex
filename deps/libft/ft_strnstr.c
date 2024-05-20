/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:42:03 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:05:15 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnstr.c
 * @dontinclude ft_strnstr.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Finds first occurence of @p needle in string @p haystack
 * 
 * @param[in] haystack Optionally null-terminated string haystack to search
 * @param[in] needle Null-terminated string needle to find
 * @param[in] len Maximum number of bytes to check
 * @retval char* Pointer to the start of the first
 * occurence of @p needle in @p haystack.  
 * If not found within @p len characters or before termination of @p haystack,
 * returns @p NULL.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hix;
	size_t	nix;

	if (!needle[0])
		return ((char *) haystack);
	hix = 0;
	while (hix < len && haystack[hix])
	{
		nix = 0;
		while (hix + nix < len && needle[nix] && haystack[hix + nix]
			&& needle[nix] == haystack[hix + nix])
			nix++;
		if (!needle[nix])
			return ((char *) haystack + hix);
		hix++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:26:19 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:06:35 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcpy.c
 * @dontinclude ft_strlcpy.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Copy at most <tt>dstsize - 1</tt> characters
 * from string @p src into @p dst
 * 
 * Null-terminates @p dst if <tt>dstsize != 0</tt>
 * 
 * @param[in, out] dst Pointer to allocated memory of at least
 * @ref ft_strlen(<tt>src</tt>) or @p dstsize size, whichever is smaller
 * @param[in] src Optionally null-terminated string
 * string
 * @param[in] dstsize Number of characters to copy, should be no greater than
 * the allocated space at @p dst
 * @retval size_t Length of @p src
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1) < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}

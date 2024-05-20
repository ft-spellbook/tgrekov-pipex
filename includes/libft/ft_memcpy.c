/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:14:33 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/06 13:37:15 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcpy.c
 * @dontinclude ft_memcpy.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Copies @p n bytes from byte string @p src to byte string @p dst
 * 
 * Copy is always performed from end to start.  
 * If your @p dst starts at any point after your @p src, even if they overlap,
 * this function is safe.  
 * If your @p dst starts prior to your @p src and overlaps it, or there is
 * a possibility of this happening, use @ref ft_memmove.
 * 
 * @param[in] dst Pointer to destination byte string
 * @param[in] src Pointer to source byte string
 * @param[in] n Number of bytes to copy
 * @retval void* @p dst
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (src != dst)
	{
		while (n--)
			((unsigned char *) dst)[n] = ((const unsigned char *) src)[n];
	}
	return (dst);
}

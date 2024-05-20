/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:24:02 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:47:05 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memmove.c
 * @dontinclude ft_memmove.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Copies @p len bytes from byte string
 * @p src to byte string @p dst non-destructively
 * 
 * @p src and @p dst may overlap in any manner, the function will switch copy
 * directions to ensure the data is copied non-destructively.
 * 
 * @param[in] dst Pointer to destination byte string
 * @param[in] src Pointer to source byte string
 * @param[in] len Number of bytes to copy
 * @retval void* @p dst
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	dir;

	if (src != dst)
	{
		i = 0;
		dir = 1;
		if (dst > src)
		{
			i = len - 1;
			dir = -1;
		}
		while (len--)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i += dir;
		}
	}
	return (dst);
}

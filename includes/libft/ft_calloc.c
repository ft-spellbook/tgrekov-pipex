/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:33:28 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/06 19:16:56 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 * @dontinclude ft_calloc.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Allocates @p count * @p size bytes with malloc
 * and returns a pointer to the result.
 * 
 * @param[in] count Number of objects to allocate for
 * @param[in] size Size of each object
 * @retval void* Freeable pointer to allocated memory after it is
 * @ref ft_bzero "filled with zeroes"  
 * If either @p count or @p size are \p 0, returns
 * <tt>@ref ft_calloc"ft_calloc"(1, 1)</tt>.  
 * If the multiplication of @p count and @p size overflows, returns \p NULL.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	bsize;

	if (!count || !size)
		return (ft_calloc(1, 1));
	bsize = count * size;
	if (bsize / count != size)
		return (0);
	ptr = malloc(bsize);
	if (!ptr)
		return (0);
	ft_bzero(ptr, bsize);
	return (ptr);
}

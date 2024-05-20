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

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (src != dst)
	{
		while (n--)
			((unsigned char *) dst)[n] = ((const unsigned char *) src)[n];
	}
	return (dst);
}

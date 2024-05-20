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

#include "libft.h"

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

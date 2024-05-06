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

#include "libft.h"

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

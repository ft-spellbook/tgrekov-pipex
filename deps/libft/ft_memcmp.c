/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:54:51 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:46:48 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcmp.c
 * @dontinclude ft_memcmp.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Compares @p n bytes of byte string @p s1 against byte string @p s2
 * 
 * Comparisons are done with <tt>unsigned char</tt>.
 * 
 * @param[in] s1 First byte string to compare
 * @param[in] s2 Second byte string to compare
 * @param[in] n Number of bytes to compare
 * @retval int Result of subtracting the differing
 * byte of @p s2 from that of @p s1.  
 * If no difference was found in @p n bytes, returns @p 0.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	while (i < n)
	{
		diff = ((unsigned char *) s1)[i] - ((unsigned char *) s2)[i];
		if (diff)
			return (diff);
		i++;
	}
	return (0);
}

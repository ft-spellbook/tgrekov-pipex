/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:03:22 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:12:24 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strdup.c
 * @dontinclude ft_strdup.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Allocates memory for, copies to, and returns a duplicate of @p s1
 * 
 * @param[in] s1 Null-terminated string to copy
 * @retval char* Null-terminated, duplicate string, result of malloc
 */
char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s2;

	size = ft_strlen(s1);
	s2 = malloc(size + 1);
	if (!s2)
		return (0);
	return (ft_memcpy(s2, s1, size + 1));
}

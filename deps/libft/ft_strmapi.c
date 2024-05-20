/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:54:37 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:12:09 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strmapi.c
 * @dontinclude ft_strmapi.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Allocates and creates a new string from the output of function
 * @p f processing each character of string @p s
 * 
 * This function iterates from end to start
 * 
 * @param[in] s Null-terminated string to iterate over
 * @param[in] f Pointer to a function that returns each character of the new
 * string individually, provided the index and value of each original character
 * @retval char* Null-terminated string populated from successive
 * applications of @p f. Result of malloc.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*s2;

	if (!s)
		return (0);
	len = ft_strlen(s);
	s2 = ft_calloc(len + 1, 1);
	if (!s2)
		return (0);
	while (len--)
		s2[len] = f(len, s[len]);
	return (s2);
}

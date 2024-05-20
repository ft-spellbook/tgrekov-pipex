/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:28:27 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:10:30 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strchr.c
 * @dontinclude ft_strchr.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Finds first occurence of character @p c in string @p s
 * 
 * Check is done as @p char
 * 
 * @param[in] s Null-terminated string haystack to search
 * @param[in] c int needle to find
 * @retval char* Pointer to first occurence of needle @p c in haystack @p s.  
 * @p NULL if none is found before the end of the string.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (char) c)
		return ((char *) s);
	return (0);
}

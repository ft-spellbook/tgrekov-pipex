/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:36:17 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/09 20:04:56 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strrchr.c
 * @dontinclude ft_strrchr.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Finds last occurence of @p c in string at @p s
 * 
 * Check is done as @p char
 * 
 * @param[in] s Null-terminated string haystack to search
 * @param[in] c int needle to find
 * @retval char* Pointer to last occurence of needle @p c in haystack @p s.  
 * @p NULL if none is found before the end of the string.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (char) c)
			last = (char *) s;
		s++;
	}
	if (*s == (char) c)
		last = (char *) s;
	return (last);
}

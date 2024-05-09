/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:41:34 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/13 22:11:57 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split.c
 * @dontinclude ft_split.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

static size_t	count_sections(char const *s, char c)
{
	size_t	i;
	size_t	sections;

	sections = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (!i || s[i - 1] == c))
			sections++;
		i++;
	}
	return (sections);
}

static char	**free_all(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

static size_t	end_of_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (ft_strlen(s));
}

/**
 * @brief Split string @p s by characer @p c into allocated array of
 * strings, with @p NULL as the last element
 * 
 * @param[in] s Null-terminated string to split
 * @param[in] c Character to split on
 * @retval char** Allocated array of allocated string pointers,
 * with @p NULL as the last element
 */
char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	arr_i;
	size_t	len;

	while (*s && *s == c)
		s++;
	arr = ft_calloc(count_sections(s, c) + 1, sizeof(char *));
	if (!arr)
		return (0);
	arr_i = 0;
	while (*s)
	{
		len = end_of_word(s, c);
		arr[arr_i] = ft_substr(s, 0, len);
		if (!arr[arr_i++])
			return (free_all(arr));
		s += len;
		while (*s && *s == c)
			s++;
	}
	return (arr);
}

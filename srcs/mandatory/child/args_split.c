/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:26 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 10:29:04 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file args_split.c
 * @dontinclude args_split.c
 * @line /\* *********
 * @until /\* *********
 */

#include "../../../includes/libft/libft.h"
#include "../utils/utils.h"

static int	_ifs(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static size_t	count_sections(char const *s)
{
	size_t	i;
	size_t	sections;
	int		quoted;

	sections = 0;
	i = 0;
	quoted = 0;
	while (s[i])
	{
		if (!_ifs(s[i]))
		{
			if (s[i] == '"')
			{
				if (quoted)
					sections++;
				quoted = !quoted;
			}
			else if (!i || (!quoted && _ifs(s[i - 1])))
				sections++;
		}
		i++;
	}
	return (sections);
}

static size_t	end_of_word(char const *s, int *was_quoted)
{
	size_t	i;
	int		quoted;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
		{
			*was_quoted = 1;
			quoted = !quoted;
		}
		if (!quoted && _ifs(s[i]))
			return (i);
		i++;
	}
	return (ft_strlen(s));
}

/**
 * @brief Argument splitter with extremely rudimentary support for
 * double-quoting segments.
 * 
 * Basically @ref ft_split if it respected quotes when the quoted segment
 * is considered it's own word. (Ends of the segment are preceeded / followed
 * by spaces / start or end of string)
 * 
 * @param s String to split arguments from
 * @retval char** Null-terminated array of arguments
 */
char	**args_split(char const *s)
{
	char	**arr;
	size_t	arr_i;
	size_t	len;
	int		was_quoted;

	while (*s && _ifs(*s))
		s++;
	arr = ft_calloc(count_sections(s) + 1, sizeof(char *));
	if (!arr)
		return (err("malloc()", 0));
	arr_i = 0;
	was_quoted = 0;
	while (*s)
	{
		len = end_of_word(s, &was_quoted);
		arr[arr_i] = ft_substr(s, was_quoted, len - was_quoted * 2);
		if (!arr[arr_i++])
			return ((char **) arr_free(err("malloc()", arr)));
		was_quoted = 0;
		s += len;
		while (*s && _ifs(*s))
			s++;
	}
	return (arr);
}

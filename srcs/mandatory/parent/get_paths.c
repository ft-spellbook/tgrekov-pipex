/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:53:12 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 10:28:42 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_paths.c
 * @dontinclude get_paths.c
 * @line /\* *********
 * @until /\* *********
 */

#include "../../../includes/libft/libft.h"
#include "../utils/utils.h"

/**
 * @brief Compare path string @p a against path string @p b, which will always
 * have a trailing forward slash.
 * 
 * @param a Path string
 * @param b Previously copied path string with trailing forward slash
 * @retval int @p 0 if identical
 */
static int	compare(void *a, void *b)
{
	int	len;
	int	blen;

	if (a == b)
		return (0);
	if (!a || !b)
		return (1);
	len = ft_strlen((char *) a);
	blen = ft_strlen((char *) b) - 1;
	if (blen > len)
		len = blen;
	return (ft_strncmp((char *) a, (char *) b, len));
}

/**
 * @brief Duplicate a path string and append a forward slash.
 * 
 * @param str Path string
 * @retval void* Path string with trailing @p /
 */
static void	*copy(void *str)
{
	char	*str2;

	if (!str)
		return (0);
	str2 = ft_strjoin((char *) str, "/");
	if (!str2)
		err("malloc()", 0);
	return (str2);
}

/**
 * @brief Create a null-terminated, unique array of paths from the environment
 * pointer @p envp. Trailing forward slashes included free of charge.
 * 
 * @param envp Environment pointer
 * @retval char** Null-terminated, deduplicated array of paths from @p envp,
 * with trailing @p /
 */
char	**get_paths(char **envp)
{
	char	**paths;
	char	**paths_uniq;

	while (*envp)
	{
		if (!ft_strncmp("PATH", *envp, 4))
		{
			paths = ft_split(*envp + 5, ':');
			if (!paths)
				return (err("malloc()", 0));
			paths_uniq = (char **) dedupe(
					(void **) paths,
					arr_len((void **) paths),
					compare, copy);
			arr_free((void **) paths);
			return (paths_uniq);
		}
		envp++;
	}
	return (0);
}

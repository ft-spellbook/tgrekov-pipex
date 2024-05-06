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

#include "../../../includes/libft/libft.h"
#include "../utils/utils.h"

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

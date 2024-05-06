/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:47:02 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/06 14:05:14 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_cmd.c
 * @dontinclude get_cmd.c
 * @line /\* *********
 * @until /\* *********
 */

#include <unistd.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "../../../includes/libft/libft.h"

/**
 * @brief Find and return the first existing file with called @p name from the
 * array of @p paths.
 * 
 * @param paths Null-terminated array of paths with trailing forward slashes
 * @param name Name of command to search for
 * @retval char* Full path to the command
 */
char	*get_cmd(char **paths, char *name)
{
	char	*cmd;

	cmd = ft_strdup(name);
	if (!cmd)
		return (err("malloc() failed while assembling path to cmd", 0));
	if (!access(cmd, F_OK))
		return (cmd);
	free(cmd);
	if (!paths)
		return (0);
	while (*paths)
	{
		cmd = ft_strjoin(*paths, name);
		if (!cmd)
			return (err("malloc() failed while assembling path to cmd", 0));
		if (!access(cmd, F_OK))
			return (cmd);
		free(cmd);
		paths++;
	}
	return (0);
}

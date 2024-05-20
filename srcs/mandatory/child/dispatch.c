/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:32:09 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/20 12:27:21 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_printf.h>
#include "../utils/utils.h"

char	**args_split(char const *s);
char	*get_cmd(char **paths, char *name);

static int	_dispatch(char **paths, char **argv, char **envp, int *in_out)
{
	char	*cmd;

	cmd = get_cmd(paths, argv[0]);
	if (!cmd)
	{
		ft_printf("%>Command not found: %s\n", 2, argv[0]);
		return (127);
	}
	if (access(cmd, X_OK))
	{
		ft_printf("%>No access to execute \"%s\"\n", 2, cmd);
		return (126);
	}
	if (dup2(in_out[0], 0) == -1)
		return ((int) err("dup2()", (void *) 1));
	if (dup2(in_out[1], 1) == -1)
		return ((int) err("dup2()", (void *) 1));
	execve(cmd, argv, envp);
	free(cmd);
	ft_printf("%>execve() failed for \"%s\": %s\n", 2, cmd, strerror(errno));
	return (1);
}

void	dispatch(char **paths, char *args, char **envp, int *in_out)
{
	char	**child_argv;
	int		code;

	if (in_out[0] == -1 || in_out[1] == -1)
	{
		arr_free((void **) paths);
		exit(1);
	}
	code = 1;
	child_argv = ft_split(args, ' ');
	if (child_argv)
	{
		code = _dispatch(paths, child_argv, envp, in_out);
		arr_free((void **) child_argv);
	}
	else
		ft_printf("%>Could not split arguments \"%s\": %s\n",
			2, args, strerror(errno));
	arr_free((void **) paths);
	exit(code);
}

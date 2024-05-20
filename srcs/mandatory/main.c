/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:59:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/20 12:27:56 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "utils/utils.h"
#include <ft_printf.h>

char	**get_paths(char **envp);
int		dispatcher(char **paths, char **argv, char **envp, int *in_out);

static int	_open(char *name, int flags, int mode)
{
	int	fd;

	fd = open(name, flags, mode);
	if (fd == -1)
		ft_printf("%>Failed to open \"%s\": %s\n", 2, name, strerror(errno));
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		in_out[2];
	int		status;

	if (argc != 5)
	{
		ft_printf("%>Wrong number of arguments: %d. Expected 4\n", 2, argc - 1);
		return (1);
	}
	in_out[1] = _open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	in_out[0] = _open(argv[1], O_RDONLY, 0);
	paths = get_paths(envp);
	status = dispatcher(paths, argv + 2, envp, in_out);
	arr_free((void **) paths);
	return (status);
}

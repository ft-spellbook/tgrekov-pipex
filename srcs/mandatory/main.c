/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:59:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 10:32:47 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "utils/utils.h"
#include "../../includes/libft/ft_printf/ft_printf.h"

char	**get_paths(char **envp);
int		dispatcher(char **paths, char **argv, char **envp, int *in_out);

static int	_open(char *name, int flags, int mode)
{
	int	fd;

	fd = open(name, flags, mode);
	if (fd >= 0)
		return (fd);
	ft_printf("%>Failed to open \"%s\": %s\n", 2, name, strerror(errno));
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		in_out[2];
	int		status;

	if (argc != 5)
	{
		ft_printf("%>Wrong number of arguments: %d. Expected 5\n", 2, argc);
		return (1);
	}
	in_out[0] = _open(argv[1], O_RDONLY, 0);
	in_out[1] = _open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	paths = get_paths(envp);
	if (!paths)
	{
		ft_printf("%>Failed to resolve path\n", 2);
		return (1);
	}
	status = dispatcher(paths, argv + 2, envp, in_out);
	arr_free((void **) paths);
	return (status);
}

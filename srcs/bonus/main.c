/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:59:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/20 12:27:07 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/main.c
 * @dontinclude srcs/bonus/main.c
 * @line /\* *********
 * @until /\* *********
 */

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "../mandatory/utils/utils.h"
#include <libft.h>
#include <ft_printf.h>

int		here_doc(char *limiter, int *in_out);
char	**get_paths(char **envp);
int		dispatcher(int n, char ***str_arrs, int *in_out);

/**
 * @brief Check if in here_doc mode, verify arguments count accordingly, and
 * set append or truncate accordingly.
 * 
 * @param argc 
 * @param argv 
 * @param is_here_doc 
 * @param trunc_append 
 */
static void	_input(int argc, char **argv, int *is_here_doc, int *trunc_append)
{
	*is_here_doc = 0;
	*trunc_append = O_TRUNC;
	if (argv[1] && !ft_strncmp("here_doc", argv[1], 8))
	{
		*is_here_doc = 1;
		*trunc_append = O_APPEND;
	}
	if (argc < (5 + *is_here_doc))
	{
		ft_printf("%>Too few arguments: %d. Expected %d+\n",
			2, argc - 1, 4 + *is_here_doc);
		exit(1);
	}
}

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
	int		is_here_doc;
	int		trunc_append;

	_input(argc, argv, &is_here_doc, &trunc_append);
	in_out[1] = _open(argv[argc - 1], O_WRONLY | O_CREAT | trunc_append,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (!is_here_doc)
		in_out[0] = _open(argv[1], O_RDONLY, 0);
	else if (!here_doc(argv[2], in_out))
		return (1);
	paths = get_paths(envp);
	status = dispatcher(argc - 3 - is_here_doc,
			(char **[]){paths, argv + 2 + is_here_doc, envp}, in_out);
	arr_free((void **) paths);
	return (status);
}

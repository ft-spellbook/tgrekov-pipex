/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:18:15 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/06 15:15:54 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../utils/utils.h"

void	dispatch(char **paths, char *args, char **envp, int *in_out);
int		wait_all(int *pids, int n, int override);

static int	child1(char ***str_arrs, int *pair, int *in_out)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return ((int) err("fork()", 0));
	if (!pid)
	{
		if (close(pair[0]) == -1)
			return ((int) err("close()", (void *) 1));
		dispatch(str_arrs[0], str_arrs[1][0], str_arrs[2],
			(int []){in_out[0], pair[1]});
	}
	return (pid);
}

static int	child2(char ***str_arrs, int *pair, int *in_out)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return ((int) err("fork()", 0));
	if (!pid)
		dispatch(str_arrs[0], str_arrs[1][1], str_arrs[2],
			(int []){pair[0], in_out[1]});
	return (pid);
}

int	dispatcher(char **paths, char **argv, char **envp, int *in_out)
{
	int	pair[2];
	int	pids[2];

	if (pipe(pair) == -1)
		return ((int) err("pipe()", (void *) 1));
	pids[0] = child1((char **[]){paths, argv, envp}, pair, in_out);
	if (!pids[0])
		return (1);
	if (close(in_out[0]) == -1)
		return (wait_all(pids, 1, (int) err("close()", (void *) 1)));
	if (close(pair[1]) == -1)
		return (wait_all(pids, 1, (int) err("close()", (void *) 1)));
	pids[1] = child2((char **[]){paths, argv, envp}, pair, in_out);
	if (!pids[1])
		return (wait_all(pids, 1, 1));
	if (close(pair[0]) == -1)
		return (wait_all(pids, 2, (int) err("close()", (void *) 1)));
	if (close(in_out[1]) == -1)
		return (wait_all(pids, 2, (int) err("close()", (void *) 1)));
	return (wait_all(pids, 2, 0));
}

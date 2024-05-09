/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:18:15 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/06 15:06:18 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../mandatory/utils/utils.h"

void	dispatch(char **paths, char *args, char **envp, int *in_out);
char	**args_split(char const *s);
int		wait_all(int *pids, int n, int override);

static int	piping(int i, int n, int *pair, int **in_out__last_out)
{
	if (!i)
		*in_out__last_out[1] = in_out__last_out[0][0];
	else
		*in_out__last_out[1] = pair[0];
	if (i == (n - 1))
		pair[1] = in_out__last_out[0][1];
	else if (pipe(pair) == -1)
		return ((int) err("pipe()", (void *) 1));
	return (0);
}

static int	_fork(int *i_n, int **pids_pair, int last_out, char ***str_arrs)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return ((int) err("fork()", 0));
	if (!pid)
	{
		free(pids_pair[0]);
		if (i_n[0] != (i_n[1] - 1) && close(pids_pair[1][0]) == -1)
		{
			free(str_arrs[0]);
			exit((int) err("close()", (void *) 1));
		}
		dispatch(str_arrs[0], str_arrs[1][i_n[0]], str_arrs[2],
			(int []){last_out, pids_pair[1][1]});
	}
	return (pid);
}

int	dispatcher(int n, char ***str_arrs, int *in_out)
{
	int	i;
	int	pair[2];
	int	last_out;
	int	*pids;

	pids = malloc(sizeof(int) * n);
	if (!pids)
		return ((int) err("malloc()", (void *) 1));
	i = 0;
	while (i < n)
	{
		if (piping(i, n, pair, (int *[]){in_out, &last_out}))
			break ;
		pids[i] = _fork((int []){i, n}, (int *[]){pids, pair},
				last_out, str_arrs);
		if (close(last_out) == -1)
			return ((int) err("close()", (void *) 1));
		if (close(pair[1]) == -1)
			return ((int) err("close()", (void *) 1));
		if (!pids[i])
			break ;
		i++;
	}
	free(pids);
	return (wait_all(pids, i, !last_out));
}

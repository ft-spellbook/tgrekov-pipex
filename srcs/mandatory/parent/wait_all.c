/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:09:05 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 10:50:17 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wait_all.c
 * @dontinclude wait_all.c
 * @line /\* *********
 * @until /\* *********
 */

#include <sys/wait.h>

/**
 * @brief Wait for first @p n processes in @p pids to change state and return
 * the last process's exit code, if it could be resolved, or @p 1.
 * 
 * @param pids Process ids to wait on
 * @param n Number of process ids
 * @param override Overrides return value if non-zero
 * @retval int Last process's exit code or @p 1
 */
int	wait_all(int *pids, int n, int override)
{
	int	i;
	int	status;

	i = 0;
	while (i < n)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		else
			status = 1;
		i++;
	}
	if (override)
		return (override);
	return (status);
}

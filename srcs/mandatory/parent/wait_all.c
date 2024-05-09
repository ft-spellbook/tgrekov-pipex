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

#include <sys/wait.h>

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:47:02 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 10:28:54 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "../../../includes/libft/libft.h"

char	*get_cmd(char **paths, char *name)
{
	char	*cmd;

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

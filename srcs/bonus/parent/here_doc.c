/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:01:21 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 12:12:09 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../mandatory/utils/utils.h"
#include "../../../includes/libft/ft_printf/ft_printf.h"
#include "../../../includes/libft/get_next_line_bonus.h"
#include "../../../includes/libft/libft.h"

static int	_cmp(const char *s1, const char *s2)
{
	int	len;
	int	len2;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2) - 1;
	if (len2 > len)
		len = len2;
	return (ft_strncmp(s1, s2, len));
}

int	here_doc(char *limiter, int *in_out)
{
	int		fds[2];
	char	*line;
	size_t	len;

	if (pipe(fds) == -1)
		return ((int) err("pipe()", 0));
	in_out[0] = fds[0];
	while (1)
	{
		ft_printf("pipex heredoc> ");
		line = get_next_line(0);
		if (!line)
			return ((int) err("get_next_line()", 0));
		len = ft_strlen(line);
		if (!_cmp(limiter, line))
			break ;
		if (write(fds[1], line, len) < 0)
			return ((int) err("write()", 0));
		free(line);
	}
	free(line);
	if (close(fds[1]))
		return ((int) err("close()", 0));
	return (1);
}

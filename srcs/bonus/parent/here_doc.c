/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:01:21 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/20 12:26:53 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file here_doc.c
 * @dontinclude here_doc.c
 * @line /\* *********
 * @until /\* *********
 */

#include <unistd.h>
#include "../../mandatory/utils/utils.h"
#include <ft_printf.h>
#include <get_next_line_bonus.h>
#include <libft.h>

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

/**
 * @brief Capture multiline input from @p stdin and write to a pipe readable
 * from @p in_out[0] until a line containing only @p limiter is reached.
 * 
 * @param limiter Character to stop reading on
 * @param in_out Input filedes, output filedes
 * @retval int @p 0 on failure, @p 1 on success
 */
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

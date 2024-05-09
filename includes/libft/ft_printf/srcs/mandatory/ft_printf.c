/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:03:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/26 10:28:29 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"
#include "utils/utils.h"
#include <stdarg.h>

int	handle_sequence(const char **format, va_list args, int *fd, int total);

static void	do_segment(const char **format, va_list args, int *fd, int *total)
{
	char	*seq_start;
	int		print_len;

	seq_start = ft_strchr(*format, '%');
	if (!seq_start)
		print_len = ft_strlen(*format);
	else
		print_len = seq_start - *format;
	if (print_len && seq_start != *format
		&& !wrap_err(write(*fd, *format, print_len), total))
		return ;
	*format += print_len;
	if (seq_start)
	{
		(*format)++;
		wrap_err(handle_sequence(format, args, fd, *total), total);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		fd;

	if (!format)
		return (-1);
	fd = STDOUT_FILENO;
	va_start(args, format);
	total = 0;
	while (total > -1 && *format)
		do_segment(&format, args, &fd, &total);
	va_end(args);
	return (total);
}

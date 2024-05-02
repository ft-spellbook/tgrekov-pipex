/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_str_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:26:03 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/26 10:29:29 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/utils/repeat_str_n.c
 * @dontinclude srcs/bonus/utils/repeat_str_n.c
 * @line /\* *********
 * @until /\* *********
 */

#include "../../../../libft.h"

static int	_repeat_str_n(const char *str, int n, int strlen, int fd)
{
	int	res;
	int	res2;

	res = 0;
	if (n > strlen)
	{
		res = _repeat_str_n(str, n - strlen, strlen, fd);
		if (res == -1)
			return (-1);
		n = strlen;
	}
	res2 = write(fd, str, n);
	if (res2 == -1)
		return (-1);
	return (res + res2);
}

/**
 * @brief Write exactly @p n characters from @p str on descriptor @p fd.
 * Repeats string if @p ft_strlen(str) is greater than @p n.
 * 
 * @param[in] str
 * @param[in] n
 * @param[in] fd
 * @retval int Number of characters written, or @p -1 on error.
 */
int	repeat_str_n(const char *str, int n, int fd)
{
	if (n < 1)
		return (0);
	return (_repeat_str_n(str, n, ft_strlen(str), fd));
}

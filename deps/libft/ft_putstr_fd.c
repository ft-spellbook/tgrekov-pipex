/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 00:06:25 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/15 23:37:16 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putstr_fd.c
 * @dontinclude ft_putstr_fd.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Write string at pointer @p s to file descriptor @p fd
 * 
 * @param[in] s Pointer to string to write
 * @param[in] fd File descriptor to write to
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

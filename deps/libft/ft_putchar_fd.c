/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 00:04:29 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:47:12 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putchar_fd.c
 * @dontinclude ft_putchar_fd.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Write character @p c to file descriptor @p fd
 * 
 * @param[in] c Character to write
 * @param[in] fd File descriptor to write to
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

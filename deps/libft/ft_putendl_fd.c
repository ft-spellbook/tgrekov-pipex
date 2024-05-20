/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 00:08:07 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:47:35 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putendl_fd.c
 * @dontinclude ft_putendl_fd.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Write string at pointer @p s followed
 * by a newline to file descriptor @p fd
 * 
 * @param[in] s Pointer to string to write
 * @param[in] fd File descriptor to write to
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:23:52 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/22 05:42:31 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line_bonus.h
 * @dontinclude get_next_line_bonus.h
 * @line /\* *********
 * @until /\* *********
 */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/**
 * @brief Set default BUFFER_SIZE if it is not defined at compile time
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/**
 * @brief Max open file descriptors per process
 */
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include "stdlib.h"
# include "unistd.h"

char	*get_next_line(int fd);

#endif

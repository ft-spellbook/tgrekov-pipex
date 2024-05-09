/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:58:03 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 07:56:48 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handlers/set_fd.c
 * @dontinclude srcs/bonus/conversion/handlers/set_fd.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/internal_types.h"

/**
 * @brief Processes the set file descriptor specifier by setting the
 * file descriptor. (Phenomenal design)
 * 
 * @param[in] seq 
 * @param[in, out] fd 
 * @param[in] total (Unused)
 * @retval int Always 0
 */
static int	process_set_fd(t_sequence seq, int *fd, int total)
{
	(void) total;
	*fd = (int) seq.data;
	return (0);
}

/**
 * @brief Preprocess the set file descriptor specifier by retrieving the
 * argument, ensuring that @ref s_subspec::min_width is @p 0, and setting
 * @ref s_sequence::process to @ref process_set_fd.
 * 
 * @param[in, out] args 
 * @param[in, out] seq 
 */
void	pre_set_fd(va_list args, t_sequence *seq)
{
	seq->data = (t_ubiggest) va_arg(args, int);
	seq->subspec.min_width = 0;
	seq->process = process_set_fd;
}

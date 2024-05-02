/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:36:38 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 07:56:54 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handlers/percent.c
 * @dontinclude srcs/bonus/conversion/handlers/percent.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/internal_types.h"

int	process_char(t_sequence seq, int *fd, int total);

/**
 * @brief Preprocess the percent specifier by setting @ref s_sequence::data
 * to @p %, @ref s_sequence::total_len to @p 1, and @ref s_sequence::process
 * to @ref process_char.
 * 
 * @param[in] args (Unused)
 * @param[in, out] seq 
 */
void	pre_percent(va_list args, t_sequence *seq)
{
	(void) args;
	seq->data = (t_ubiggest) '%';
	seq->total_len = 1;
	seq->process = process_char;
}

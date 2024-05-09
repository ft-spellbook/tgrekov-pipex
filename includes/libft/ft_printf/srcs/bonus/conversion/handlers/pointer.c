/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:38:51 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 07:35:14 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handlers/pointer.c
 * @dontinclude srcs/bonus/conversion/handlers/pointer.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"

int	process_uhex(t_sequence seq, int *fd, int total);

/**
 * @brief Preprocess the pointer specifier by retrieving the address,
 * setting the @ref s_sequence::total_len with
 * @ref u_len_base"u_len_base(ptr, 16)", setting the
 * @ref s_sequence::sign"prefix" to @p 0x, and setting the
 * @ref s_sequence::process to @ref process_uhex.
 * 
 * @param[in, out] args 
 * @param[in, out] seq 
 */
void	pre_ptr(va_list args, t_sequence *seq)
{
	seq->data = (unsigned long long) va_arg(args, void *);
	seq->total_len = u_len_base(seq->data, 16);
	seq->sign = "0x";
	seq->process = process_uhex;
}

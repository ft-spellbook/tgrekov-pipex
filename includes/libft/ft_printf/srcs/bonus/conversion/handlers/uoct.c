/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uoct.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:59:50 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 08:21:03 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handlers/uoct.c
 * @dontinclude srcs/bonus/conversion/handlers/uoct.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"
#include "utils/handler_utils.h"

/**
 * @brief Process the unsigned octal specifier by
 * @ref u_print_base"printing" the number in base 8.
 * 
 * @param[in] seq 
 * @param[in] fd 
 * @param[in] total (Unused) 
 * @retval int Return value of @ref u_print_base
 */
static int	process_uoct(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (u_print_base(seq, *fd, "01234567"));
}

/**
 * @brief Preprocess the unsigned octal specifier by
 * @ref unsigned_arg"retrieving" the argument in the
 * @ref e_lenmod"appropriate size", setting the @ref s_sequence::total_len
 * with @ref u_len_base"u_len_base(nbr, 8)" and the @ref s_subspec::precision,
 * ensuring that @ref s_subspec::pad_str is set to spaces if the
 * @ref s_subspec::precision is set, setting @ref s_sequence::sign to @p 0 if
 * @ref s_subspec::force_decimal is set and the retrieved value is non-zero,
 * and setting the @ref s_sequence::process to @ref process_uoct.
 * 
 * @param[in, out] args 
 * @param[in, out] seq 
 */
void	pre_uoct(va_list args, t_sequence *seq)
{
	seq->data = unsigned_arg(args, seq->subspec.lenmod);
	seq->total_len = u_len_base(seq->data, 8)
		- (!seq->subspec.precision && !seq->data);
	if (seq->subspec.precision > seq->total_len)
		seq->total_len = seq->subspec.precision;
	if (seq->subspec.precision != -1)
		seq->subspec.pad_str = "          ";
	if (seq->subspec.force_decimal && seq->data)
		seq->sign = "0";
	seq->process = process_uoct;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:50:06 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 08:17:50 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handlers/uint.c
 * @dontinclude srcs/bonus/conversion/handlers/uint.c
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
 * @brief Processes the unsigned integer specifier by
 * @ref u_print_base"printing" the number in base 10.
 * 
 * @param[in] seq 
 * @param[in] fd 
 * @param[in] total (Unused)
 * @retval int Return value of @ref u_print_base
 */
int	process_uint(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (u_print_base(seq, *fd, "0123456789"));
}

/**
 * @brief Preprocess the unsigned integer specifier by
 * @ref unsigned_arg"retrieving" the argument in the
 * @ref e_lenmod"appropriate size", setting the @ref s_sequence::total_len
 * with @ref u_len_base"u_len_base(nbr, 10)" and the @ref s_subspec::precision,
 * ensuring that @ref s_subspec::pad_str is set to spaces if the
 * @ref s_subspec::precision is set, and setting the @ref s_sequence::process
 * to @ref process_uint.
 * 
 * @param[in, out] args 
 * @param[in, out] seq 
 */
void	pre_uint(va_list args, t_sequence *seq)
{
	seq->data = unsigned_arg(args, seq->subspec.lenmod);
	seq->total_len = u_len_base(seq->data, 10)
		- (!seq->subspec.precision && !seq->data);
	if (seq->subspec.precision > seq->total_len)
		seq->total_len = seq->subspec.precision;
	if (seq->subspec.precision != -1)
		seq->subspec.pad_str = "          ";
	seq->process = process_uint;
}

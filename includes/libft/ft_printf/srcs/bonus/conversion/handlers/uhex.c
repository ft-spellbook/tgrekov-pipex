/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:07:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 08:23:23 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handlers/uhex.c
 * @dontinclude srcs/bonus/conversion/handlers/uhex.c
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
 * @ref u_print_base"printing" the number in uppercase or lowercase base 16
 * depending on whether @ref s_sequence::specifier is @p x or @p X.
 * 
 * @param[in] seq 
 * @param[in] fd 
 * @param[in] total (Unused) 
 * @retval int Return value of @ref u_print_base
 */
int	process_uhex(t_sequence seq, int *fd, int total)
{
	(void) total;
	if (seq.specifier == 'X')
		return (u_print_base(seq, *fd, "0123456789ABCDEF"));
	return (u_print_base(seq, *fd, "0123456789abcdef"));
}

/**
 * @brief Preprocess the unsigned hexadecimal specifier by
 * @ref unsigned_arg"retrieving" the argument in the
 * @ref e_lenmod"appropriate size", setting the @ref s_sequence::total_len
 * with @ref u_len_base"u_len_base(nbr, 16)" and the @ref s_subspec::precision,
 * ensuring that @ref s_subspec::pad_str is set to spaces if the
 * @ref s_subspec::precision is set, setting @ref s_sequence::sign to @p 0x or
 * @p 0X if @ref s_subspec::force_decimal is set and the retrieved value is
 * non-zero, and setting the @ref s_sequence::process to @ref process_uhex.
 * 
 * @param[in, out] args 
 * @param[in, out] seq 
 */
void	pre_uhex(va_list args, t_sequence *seq)
{
	seq->data = unsigned_arg(args, seq->subspec.lenmod);
	seq->total_len = u_len_base(seq->data, 16)
		- (!seq->subspec.precision && !seq->data);
	if (seq->subspec.precision > seq->total_len)
		seq->total_len = seq->subspec.precision;
	if (seq->subspec.precision != -1)
		seq->subspec.pad_str = "          ";
	if (seq->subspec.force_decimal && seq->data)
	{
		seq->sign = "0x";
		if (seq->specifier == 'X')
			seq->sign = "0X";
	}
	seq->process = process_uhex;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:41:27 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 07:16:49 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/identify_sequence.c
 * @dontinclude srcs/bonus/conversion/identify_sequence.c
 * @line /\* *********
 * @until /\* *********
 */

#include "handlers/handlers.h"
#include "sequence.h"

/**
 * @brief Sets initial values for a @ref s_sequence that are not always set
 * elsewhere.
 * 
 * @param[in, out] sequence 
 */
static void	init_sequence(t_sequence *sequence)
{
	sequence->sign = 0;
	sequence->total_len = 0;
	sequence->pad_len = 0;
}

/**
 * @brief Initialize a @ref s_sequence and determine which specifier it needs
 * to handle, and runs the preprocessing function for that specifier.
 * Sets @ref s_sequence::specifier to @p 0 on failure.
 * 
 * @param[in, out] args 
 * @param[in, out] seq 
 */
void	identify_sequence(va_list args, t_sequence *seq)
{
	init_sequence(seq);
	if (seq->specifier == 'd' || seq->specifier == 'i')
		return (pre_int(args, seq));
	if (seq->specifier == 'u')
		return (pre_uint(args, seq));
	if (seq->specifier == 'o')
		return (pre_uoct(args, seq));
	if (seq->specifier == 'x' || seq->specifier == 'X')
		return (pre_uhex(args, seq));
	if (seq->specifier == 'c')
		return (pre_char(args, seq));
	if (seq->specifier == 's')
		return (pre_string(args, seq));
	if (seq->specifier == 'p')
		return (pre_ptr(args, seq));
	if (seq->specifier == '%')
		return (pre_percent(args, seq));
	if (seq->specifier == 'n')
		return (pre_store(args, seq));
	if (seq->specifier == '>')
		return (pre_set_fd(args, seq));
	seq->specifier = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:41:27 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/11 23:50:53 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers/handlers.h"
#include "sequence.h"

static void	init_sequence(t_sequence *sequence)
{
	sequence->sign = 0;
	sequence->total_len = 0;
}

void	identify_sequence(va_list args, t_sequence *seq)
{
	init_sequence(seq);
	if (seq->specifier == 'd' || seq->specifier == 'i')
		return (pre_int(args, seq));
	if (seq->specifier == 'u')
		return (pre_uint(args, seq));
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
	seq->specifier = 0;
}

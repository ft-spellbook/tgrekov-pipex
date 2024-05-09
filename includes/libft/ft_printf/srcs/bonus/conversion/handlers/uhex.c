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

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"
#include "utils/handler_utils.h"

int	process_uhex(t_sequence seq, int *fd, int total)
{
	(void) total;
	if (seq.specifier == 'X')
		return (u_print_base(seq, *fd, "0123456789ABCDEF"));
	return (u_print_base(seq, *fd, "0123456789abcdef"));
}

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

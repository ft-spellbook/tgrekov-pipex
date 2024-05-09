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

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"
#include "utils/handler_utils.h"

int	process_uint(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (u_print_base(seq, *fd, "0123456789"));
}

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

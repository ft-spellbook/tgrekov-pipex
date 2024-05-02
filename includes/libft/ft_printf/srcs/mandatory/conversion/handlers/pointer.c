/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:38:51 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 04:30:33 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"

int	process_uhex(t_sequence seq, int *fd, int total);

void	pre_ptr(va_list args, t_sequence *seq)
{
	seq->data = (unsigned long long) va_arg(args, void *);
	seq->total_len = u_len_base(seq->data, 16);
	seq->sign = "0x";
	seq->process = process_uhex;
}

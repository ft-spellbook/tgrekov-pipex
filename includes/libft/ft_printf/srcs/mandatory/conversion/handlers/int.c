/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:18:23 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/12 00:46:41 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"

int	process_uint(t_sequence seq, int *fd, int total);

static t_ubiggest	lltull(t_biggest n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	pre_int(va_list args, t_sequence *seq)
{
	t_biggest	n;

	n = va_arg(args, int);
	if (n < 0)
		seq->sign = "-";
	seq->data = lltull(n);
	seq->total_len = u_len_base(seq->data, 10);
	seq->process = process_uint;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:50:06 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/11 23:50:31 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"

int	process_uint(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (u_put_base(seq.data, "0123456789", *fd));
}

void	pre_uint(va_list args, t_sequence *seq)
{
	seq->data = va_arg(args, unsigned int);
	seq->total_len = u_len_base(seq->data, 10);
	seq->process = process_uint;
}

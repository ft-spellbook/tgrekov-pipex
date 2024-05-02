/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:07:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/11 23:50:09 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"

int	process_uhex(t_sequence seq, int *fd, int total)
{
	(void) total;
	if (seq.specifier == 'X')
		return (u_put_base(seq.data, "0123456789ABCDEF", *fd));
	return (u_put_base(seq.data, "0123456789abcdef", *fd));
}

void	pre_uhex(va_list args, t_sequence *seq)
{
	seq->data = va_arg(args, unsigned int);
	seq->total_len = u_len_base(seq->data, 16);
	seq->process = process_uhex;
}

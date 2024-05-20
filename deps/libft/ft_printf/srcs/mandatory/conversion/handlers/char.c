/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:22:38 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 03:56:57 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/internal_types.h"

int	process_char(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (write(*fd, (char *) &seq.data, 1));
}

void	pre_char(va_list args, t_sequence *seq)
{
	seq->data = (t_ubiggest) va_arg(args, int);
	seq->total_len = 1;
	seq->process = process_char;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:18:34 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 08:47:35 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../sequence.h"
#include "../../utils/internal_types.h"

static int	process_store(t_sequence seq, int *fd, int total)
{
	(void) fd;
	if (!seq.data)
		return (-1);
	if (seq.subspec.lenmod == hh)
		*((signed char *) seq.data) = total;
	else if (seq.subspec.lenmod == h)
		*((short *) seq.data) = total;
	else if (seq.subspec.lenmod == l)
		*((long *) seq.data) = total;
	else if (seq.subspec.lenmod == ll)
		*((long long *) seq.data) = total;
	else if (seq.subspec.lenmod == j)
		*((intmax_t *) seq.data) = total;
	else if (seq.subspec.lenmod == z)
		*((size_t *) seq.data) = total;
	else if (seq.subspec.lenmod == t)
		*((t_ptrdiff_t *) seq.data) = total;
	else
		*((int *) seq.data) = total;
	return (0);
}

void	pre_store(va_list args, t_sequence *seq)
{
	if (seq->subspec.lenmod == hh)
		seq->data = (t_ubiggest) va_arg(args, int *);
	else if (seq->subspec.lenmod == h)
		seq->data = (t_ubiggest) va_arg(args, int *);
	else if (seq->subspec.lenmod == l)
		seq->data = (t_ubiggest) va_arg(args, long *);
	else if (seq->subspec.lenmod == ll)
		seq->data = (t_ubiggest) va_arg(args, long long *);
	else if (seq->subspec.lenmod == j)
		seq->data = (t_ubiggest) va_arg(args, intmax_t *);
	else if (seq->subspec.lenmod == z)
		seq->data = (t_ubiggest) va_arg(args, size_t *);
	else if (seq->subspec.lenmod == t)
		seq->data = (t_ubiggest) va_arg(args, t_ptrdiff_t *);
	else
		seq->data = (t_ubiggest) va_arg(args, int *);
	seq->subspec.min_width = 0;
	seq->process = process_store;
}

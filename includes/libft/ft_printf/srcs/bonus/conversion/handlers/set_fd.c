/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:58:03 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 07:56:48 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/internal_types.h"

static int	process_set_fd(t_sequence seq, int *fd, int total)
{
	(void) total;
	*fd = (int) seq.data;
	return (0);
}

void	pre_set_fd(va_list args, t_sequence *seq)
{
	seq->data = (t_ubiggest) va_arg(args, int);
	seq->subspec.min_width = 0;
	seq->process = process_set_fd;
}

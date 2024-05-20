/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:25:24 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/26 10:29:57 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../../../../libft.h"
#include "../../utils/internal_types.h"

static int	process_string(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (write(*fd, (char *) seq.data, seq.total_len - seq.pad_len));
}

void	pre_string(va_list args, t_sequence *seq)
{
	seq->data = (t_ubiggest) va_arg(args, char *);
	if (!seq->data)
		seq->data = (t_ubiggest) "(null)";
	seq->total_len = (int) ft_strlen((char *) seq->data);
	if (seq->subspec.precision > -1 && seq->subspec.precision < seq->total_len)
		seq->total_len = seq->subspec.precision;
	seq->process = process_string;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:36:38 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 03:56:55 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/internal_types.h"

int	process_char(t_sequence seq, int *fd, int total);

void	pre_percent(va_list args, t_sequence *seq)
{
	(void) args;
	seq->data = (t_ubiggest) '%';
	seq->total_len = 1;
	seq->process = process_char;
}

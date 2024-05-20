/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:41:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/26 10:28:55 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "sequence.h"
#include "../utils/utils.h"
#include "../../../../libft.h"

void	identify_sequence(va_list args, t_sequence *seq);

int	handle_sequence(const char **format, va_list args, int *fd, int total)
{
	t_sequence	seq;
	int			res;

	seq.specifier = **format;
	identify_sequence(args, &seq);
	if (!seq.specifier)
		return (-1);
	if (seq.sign)
		seq.total_len += ft_strlen(seq.sign);
	(*format)++;
	res = 0;
	if (seq.sign && !wrap_err(write(*fd, seq.sign, ft_strlen(seq.sign)), &res))
		return (-1);
	if (!wrap_err(seq.process(seq, fd, total + res), &res))
		return (-1);
	return (res);
}

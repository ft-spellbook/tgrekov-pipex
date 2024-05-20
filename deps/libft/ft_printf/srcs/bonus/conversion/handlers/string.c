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

/**
 * @file srcs/bonus/conversion/handlers/string.c
 * @dontinclude srcs/bonus/conversion/handlers/string.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../../../../libft.h"
#include "../../utils/internal_types.h"

/**
 * @brief Process the string specifier by writing the string. (Rocket science)
 * 
 * @param[in] seq 
 * @param[in] fd 
 * @param[in] total (Unused)
 * @retval int Output of @p write
 */
static int	process_string(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (write(*fd, (char *) seq.data, seq.total_len - seq.pad_len));
}

/**
 * @brief Preprocess the string specifier by retrieving the address,
 * setting @ref s_sequence::data to the address, or to @p "(null)" if it is
 * null, setting @ref s_sequence::total_len to the length of the string
 * or the @ref s_subspec::precision, if it is specified and less than the
 * length, and setting @ref s_sequence::process to @ref process_string.
 * 
 * @param[in, out] args 
 * @param[in, out] seq 
 */
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

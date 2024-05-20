/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:41:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/26 10:29:48 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handle_sequence.c
 * @dontinclude srcs/bonus/conversion/handle_sequence.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include "sequence.h"
#include "../utils/utils.h"
#include "../../../../libft.h"

void	init_subspec(t_subspec *subspec);
void	identify_sequence(va_list args, t_sequence *seq);
void	parse_subspec(const char **format, t_subspec *subspec, va_list args);

/**
 * @brief Print appropriate padding characters on either side, as well as the
 * @ref s_sequence::sign"sign / prefix", and call the processing function for
 * the given specifier.
 * 
 * @param[in] seq 
 * @param[in, out] fd 
 * @param[in] total 
 * @retval int Number of characters printed, or @p -1 on error.
 */
static int	print(t_sequence seq, int *fd, int total)
{
	int	res;

	res = 0;
	if (seq.pad_len && !seq.subspec.left_justify
		&& seq.subspec.pad_str[0] != '0'
		&& !wrap_err(repeat_str_n(seq.subspec.pad_str, seq.pad_len, *fd), &res))
		return (-1);
	if (seq.sign && !wrap_err(write(*fd, seq.sign, ft_strlen(seq.sign)), &res))
		return (-1);
	if (seq.pad_len && !seq.subspec.left_justify
		&& seq.subspec.pad_str[0] == '0'
		&& !wrap_err(repeat_str_n(seq.subspec.pad_str, seq.pad_len, *fd), &res))
		return (-1);
	if (!wrap_err(seq.process(seq, fd, total + res), &res))
		return (-1);
	if (seq.pad_len && seq.subspec.left_justify
		&& !wrap_err(repeat_str_n(seq.subspec.pad_str, seq.pad_len, *fd), &res))
		return (-1);
	return (res);
}

/**
 * @brief Prepares and executes a sequence.
 * 
 * @ref init_subspec"Initializes" and @ref parse_subspec"parses" any
 * @ref s_subspec"subspecifiers", @ref identify_sequence"identifies" the
 * sequence and executes the preprocessor for it, adds up the final
 * @ref s_sequence::total_len"predicted lengths", @ref "prints" padding,
 * prefixes, and executes the processor for the sequence.
 * 
 * @param[in, out] format 
 * @param[in, out] args 
 * @param[in, out] fd 
 * @param[in] total 
 * @retval int Number of characters printed, or @p -1 on error.
 */
int	handle_sequence(const char **format, va_list args, int *fd, int total)
{
	t_sequence	seq;

	init_subspec(&seq.subspec);
	parse_subspec(format, &seq.subspec, args);
	seq.specifier = **format;
	identify_sequence(args, &seq);
	if (!seq.specifier)
		return (-1);
	if (seq.sign)
		seq.total_len += ft_strlen(seq.sign);
	if (seq.subspec.min_width > seq.total_len)
		seq.pad_len = seq.subspec.min_width - seq.total_len;
	seq.total_len += seq.pad_len;
	(*format)++;
	return (print(seq, fd, total));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:18:23 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 08:37:14 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handlers/int.c
 * @dontinclude srcs/bonus/conversion/handlers/int.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"

int	process_uint(t_sequence seq, int *fd, int total);

/**
 * @brief Retrieves the next signed variable argument in the appropriate
 * size dependent on the @ref e_lenmod"length modifier".
 * 
 * For more info on the length modifiers, see @ref ft_printf.c
 * 
 * @param[in, out] args 
 * @param[in] lenmod
 * @retval t_biggest Retrieved value
 */
static t_biggest	signed_arg(va_list args, t_lenmod lenmod)
{
	if (lenmod == hh)
		return ((signed char) va_arg(args, int));
	if (lenmod == h)
		return ((short) va_arg(args, int));
	if (lenmod == l)
		return (va_arg(args, long));
	if (lenmod == ll)
		return (va_arg(args, long long));
	if (lenmod == j)
		return (va_arg(args, intmax_t));
	if (lenmod == z)
		return (va_arg(args, size_t));
	if (lenmod == t)
		return (va_arg(args, t_ptrdiff_t));
	return (va_arg(args, int));
}

/**
 * @brief Safely converts a signed integer to an unsigned one.
 * 
 * @param[in] n 
 * @retval t_ubiggest Converted integer
 */
static t_ubiggest	lltull(t_biggest n)
{
	if (n == -T_BIGGEST_MAX - 1LL)
		return ((t_ubiggest)(-(n + 1)) + 1ULL);
	if (n < 0)
		n = -n;
	return (n);
}

/**
 * @brief Preprocess the signed integer specifier by
 * @ref signed_arg"retrieving" the argument in the
 * @ref e_lenmod"appropriate size", setting @ref s_sequence::sign to @p - if
 * the number was negative, @ref lltull"converting" it from signed to unsigned,
 * setting the @ref s_sequence::total_len with
 * @ref u_len_base"u_len_base(nbr, 10)" and the @ref s_subspec::precision,
 * ensuring that @ref s_subspec::pad_str is set to spaces if the
 * @ref s_subspec::precision is set, setting @ref s_sequence::sign to
 * @ref s_subspec::forced_sign if it was not already set to @p -, and setting
 * the @ref s_sequence::process to @ref process_uint.
 * 
 * @param[in, out] args 
 * @param[in, out] seq 
 */
void	pre_int(va_list args, t_sequence *seq)
{
	t_biggest	n;

	n = signed_arg(args, seq->subspec.lenmod);
	if (n < 0)
		seq->sign = "-";
	seq->data = lltull(n);
	seq->total_len = u_len_base(seq->data, 10)
		- (!seq->subspec.precision && !seq->data);
	if (seq->subspec.precision > seq->total_len)
		seq->total_len = seq->subspec.precision;
	if (seq->subspec.precision != -1)
		seq->subspec.pad_str = "          ";
	if (seq->subspec.forced_sign && !seq->sign)
		seq->sign = seq->subspec.forced_sign;
	seq->process = process_uint;
}

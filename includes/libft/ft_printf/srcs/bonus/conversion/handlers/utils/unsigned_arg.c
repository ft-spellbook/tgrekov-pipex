/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 07:31:57 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 08:36:45 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handlers/utils/unsigned_arg.c
 * @dontinclude srcs/bonus/conversion/handlers/utils/unsigned_arg.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include <stdlib.h>
#include "../../subspec.h"
#include "../../../utils/internal_types.h"

/**
 * @brief Retrieves the next unsigned variable argument in the appropriate
 * size dependent on the @ref e_lenmod"length modifier".
 * 
 * For more info on the length modifiers, see @ref ft_printf.c
 * 
 * @param[in, out] args 
 * @param[in] lenmod 
 * @retval t_ubiggest Retrieved value
 */
t_ubiggest	unsigned_arg(va_list args, t_lenmod lenmod)
{
	if (lenmod == hh)
		return ((unsigned char) va_arg(args, unsigned int));
	if (lenmod == h)
		return ((unsigned short) va_arg(args, unsigned int));
	if (lenmod == l)
		return (va_arg(args, unsigned long));
	if (lenmod == ll)
		return (va_arg(args, unsigned long long));
	if (lenmod == j)
		return (va_arg(args, uintmax_t));
	if (lenmod == z)
		return (va_arg(args, size_t));
	if (lenmod == t)
		return (va_arg(args, t_ptrdiff_t));
	return (va_arg(args, unsigned int));
}

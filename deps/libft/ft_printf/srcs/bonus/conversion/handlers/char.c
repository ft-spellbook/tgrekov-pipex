/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:22:38 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 07:56:59 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/handlers/char.c
 * @dontinclude srcs/bonus/conversion/handlers/char.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdarg.h>
#include <unistd.h>
#include "../sequence.h"
#include "../../utils/internal_types.h"

/**
 * @brief Processes the character specifier by writing a character. (Wow)
 * 
 * @param[in] seq 
 * @param[in] fd 
 * @param[in] total (Unused)
 * @retval int Output of @p write
 */
int	process_char(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (write(*fd, (char *) &seq.data, 1));
}

/**
 * @brief Preprocess the character specifier by retrieving the character,
 * setting @ref s_sequence::total_len to 1 and @ref s_sequence::process
 * to @ref process_char.
 * 
 * @param[in, out] args 
 * @param[in, out] seq 
 */
void	pre_char(va_list args, t_sequence *seq)
{
	seq->data = (t_ubiggest) va_arg(args, int);
	seq->total_len = 1;
	seq->process = process_char;
}

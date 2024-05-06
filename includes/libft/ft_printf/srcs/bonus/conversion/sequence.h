/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:46:53 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 06:56:24 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/sequence.h
 * @dontinclude srcs/bonus/conversion/sequence.h
 * @line /\* *********
 * @until /\* *********
 */

#ifndef SEQUENCE_H
# define SEQUENCE_H

# include <unistd.h>
# include "subspec.h"
# include "../utils/internal_types.h"

/**
 * @struct s_sequence
 * @brief Holds information regarding the current format specifier sequence.
 * @typedef t_sequence
 * @copybrief s_sequence
 * @property s_sequence::specifier
 * @brief The specifier character for this sequence.
 * @property s_sequence::subspec
 * @copybrief s_subspec
 * @property s_sequence::sign
 * @brief String containing the prefix for the value. Set during preprocessing
 * for a format handler.
 * @property s_sequence::data
 * @brief Retrieved variable argument.
 * @property s_sequence::total_len
 * @brief Total number of characters after padding.
 * @property s_sequence::pad_len
 * @brief Number of characters to pad.
 * @property s_sequence::process
 * @brief Function to use for processing this sequence's value.
 */
typedef struct s_sequence
{
	char				specifier;
	t_subspec			subspec;
	char				*sign;
	t_ubiggest			data;
	int					total_len;
	int					pad_len;
	int					(*process)(struct s_sequence, int *, int);
}	t_sequence;

#endif
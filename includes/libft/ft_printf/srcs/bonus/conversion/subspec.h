/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subspec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:20:17 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 06:52:53 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/conversion/subspec.h
 * @dontinclude srcs/bonus/conversion/subspec.h
 * @line /\* *********
 * @until /\* *********
 */

#ifndef SUBSPEC_H
# define SUBSPEC_H

/**
 * @brief Represents the length modifiers for a format specifier's
 * variable argument.
 */
typedef enum e_lenmod
{
	none	= 0,
	hh		= 1,
	h		= 2,
	l		= 3,
	ll		= 4,
	j		= 5,
	z		= 6,
	t		= 7,
}	t_lenmod;

/**
 * @struct s_subspec
 * @brief Holds subspecifier options for a format specifier.
 * @typedef t_subspec
 * @copybrief s_subspec
 * @property s_subspec::left_justify
 * @brief 1 or 0, whether padding should left justify.
 * @property s_subspec::forced_sign
 * @brief String to print before the value. Set before preprocessing for a
 * format handler. Will be overriden, discarded, or copied to
 * @ref s_sequence"s_sequence::sign" during preprocessing.
 * @property s_subspec::force_decimal
 * @brief 1 or 0, whether or not to prefix octals or hexadecimals with their
 * respective prefixes. Named for its behavior when used with floating point
 * specifiers, to always include the decimal.
 * @property s_subspec::pad_str
 * @brief String used when padding values.
 * @property s_subspec::min_width
 * @brief Minimum number of characters to be printed.
 * @property s_subspec::precision
 * @brief Minimum number of digits to be printed, or maximum characters
 * for strings.
 * @property s_subspec::lenmod
 * @copybrief e_lenmod
 */
typedef struct s_subspec
{
	char		left_justify;
	char		*forced_sign;
	char		force_decimal;
	char		*pad_str;
	int			min_width;
	int			precision;
	t_lenmod	lenmod;
}	t_subspec;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:49:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 07:10:29 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/mandatory/wrap_err.c
 * @dontinclude srcs/mandatory/wrap_err.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Wrapper for handling functions that return a positive integer on
 * success and @p -1 on failure. Either adds positive integer @p n to the
 * value at @p total, or sets it to @p -1.
 * 
 * @param[in] n 
 * @param[in, out] total 
 * @retval int If @p n is positive, returns @p 1. Return @p 0 if it is @p -1.
 */
int	wrap_err(int n, int *total)
{
	if (n == -1)
	{
		*total = -1;
		return (0);
	}
	*total += n;
	return (1);
}

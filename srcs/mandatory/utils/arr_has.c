/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_has.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:40:50 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 10:27:46 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file arr_has.c
 * @dontinclude arr_has.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Check null-terminated array @p arr for entry @p content
 * using comparison function @p compare.
 * 
 * @param arr Array to check
 * @param len Number of elements to check
 * @param content Content to @p compare against
 * @param compare Function that compares two <tt>void *</tt>, returning @p 0 if
 * they match
 * @retval int @p 1 if the content was found, otherwise @p 0
 */
int	arr_has(void **arr, int len, void *content,
			int (*compare)(void *, void *))
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!compare(content, arr[i++]))
			return (1);
	}
	return (0);
}

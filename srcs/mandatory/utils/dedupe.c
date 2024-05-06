/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dedupe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:05:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/06 14:19:09 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dedupe.c
 * @dontinclude dedupe.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdlib.h>
#include "utils.h"
#include <stdio.h>

/**
 * @brief Create new null-terminated array containing only unique values from
 * @p arr, checked with @p compare, and copied with @p copy.
 * 
 * @param arr Array to deduplicate
 * @param compare Function that compares two <tt>void *</tt>, returning @p 0 if
 * they match
 * @param copy Function that creates and returns
 * a duplicate of it's <tt>void *</tt> argument
 * @retval void** New, deduplicated null-terminated array
 */
void	**dedupe(void **arr,
				int (*compare)(void *, void *),
				void *(*copy)(void *))
{
	int		len;
	void	**arr2;
	void	**arr3;
	int		i;
	int		i2;

	len = arr_len(arr);
	arr2 = malloc(sizeof(void *) * (len + 1));
	if (!arr2)
		return (err("malloc()", 0));
	i = 0;
	i2 = 0;
	while (arr[i])
	{
		if (!arr_has(arr2, arr[i++], compare))
		{
			arr2[i2] = copy(arr[i - 1]);
			if (arr[i - 1] && !arr2[i2++])
				return (arr_free(arr2));
		}
	}
	arr2[i2] = 0;
	arr3 = arr_cut(arr2, i2);
	free(arr2);
	return (arr3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:40:30 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 10:27:32 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file arr_cut.c
 * @dontinclude arr_cut.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdlib.h>
#include "utils.h"

/**
 * @brief Create new null-terminated array
 * containing first @p len elements of @p arr.
 * 
 * @param arr Source array to duplicate
 * @param len Number of elements to duplicate
 * @retval void** Null-terminated array containing
 * first @p len elements of @p arr
 */
void	**arr_cut(void **arr, int len)
{
	void	**arr2;

	arr2 = malloc(sizeof(void *) * len);
	if (!arr2)
		return (err("malloc()", 0));
	while (len--)
		arr2[len] = arr[len];
	return (arr2);
}

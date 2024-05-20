/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:52:00 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/06 14:03:44 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file arr_free.c
 * @dontinclude arr_free.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdlib.h>

/**
 * @brief Free each element in a null-terminated array,
 * and then the array itself.
 * 
 * @param arr Array to free
 * @retval void** Always @p 0. Used for convenience
 */
void	**arr_free(void **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

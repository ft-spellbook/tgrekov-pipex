/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dedupe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:05:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 10:28:02 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	**dedupe(void **arr, int len,
				int (*compare)(void *, void *),
				void *(*copy)(void *))
{
	void	**arr2;
	void	**arr3;
	int		i;
	int		i2;

	arr2 = malloc(sizeof(void *) * len);
	if (!arr2)
		return (err("malloc()", 0));
	i = 0;
	i2 = 0;
	while (i < len)
	{
		if (!arr_has(arr2, i2, arr[i], compare))
		{
			arr2[i2] = copy(arr[i]);
			if (arr[i] && !arr2[i2++])
				return (arr_free(arr2));
		}
		i++;
	}
	arr3 = arr_cut(arr2, i2);
	free(arr2);
	return (arr3);
}

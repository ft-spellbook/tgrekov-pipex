/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dedupe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:05:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/20 12:27:49 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "utils.h"

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
	arr2 = ft_calloc(len + 1, sizeof(void *));
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
	arr3 = arr_cut(arr2, i2);
	free(arr2);
	return (arr3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:40:30 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/06 14:18:39 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	**arr_cut(void **arr, int len)
{
	void	**arr2;

	arr2 = malloc(sizeof(void *) * len);
	if (!arr2)
		return (err("malloc()", 0));
	arr2[len] = 0;
	while (len--)
		arr2[len] = arr[len];
	return (arr2);
}

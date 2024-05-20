/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_has.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:40:50 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/06 14:16:47 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arr_has(void **arr, void *content,
			int (*compare)(void *, void *))
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!compare(content, arr[i++]))
			return (1);
	}
	return (0);
}

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

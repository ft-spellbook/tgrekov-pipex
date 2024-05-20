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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_len_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:31:15 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 06:26:12 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_types.h"

int	u_len_base(t_ubiggest n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

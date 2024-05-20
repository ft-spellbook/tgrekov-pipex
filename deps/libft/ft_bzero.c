/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:09:47 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:24:47 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_bzero.c
 * @dontinclude ft_bzero.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Write @p n zeroes to byte string at pointer @p s
 * 
 * @param[in] s Pointer to start of byte string
 * @param[in] n Number of zeroes to write
 */
void	ft_bzero(void *s, size_t n)
{
	while (n--)
		((unsigned char *) s)[n] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:35:10 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:24:41 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isprint.c
 * @dontinclude ft_isprint.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Is @p c a printable character
 * 
 * @param[in] c Character to test
 * @retval int @p 1 if @p c is within the range '<tt> </tt>' - @p ~
 */
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

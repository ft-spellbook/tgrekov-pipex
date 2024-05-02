/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:33:15 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:24:43 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isascii.c
 * @dontinclude ft_isascii.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Is @p c in the ASCII character range
 * 
 * @param[in] c Character to test
 * @retval int @p 1 if @p c is within the range @p 0 - @p 127, otherwise @p 0
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

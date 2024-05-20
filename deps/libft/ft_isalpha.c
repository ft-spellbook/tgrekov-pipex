/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:47:27 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:24:44 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalpha.c
 * @dontinclude ft_isalpha.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Is @p c an alphabetical character
 * 
 * @param[in] c Character to test
 * @retval int @p 1 if @p c is within either of the ranges
 * @p A - @p Z or @p a - @p z, otherwise @p 0
 */
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

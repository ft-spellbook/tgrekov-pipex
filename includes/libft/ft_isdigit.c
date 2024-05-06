/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:26:17 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:24:42 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isdigit.c
 * @dontinclude ft_isdigit.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Is @p c a numeric character
 * 
 * @param[in] c Character to test
 * @retval int @p 1 if @p c is within the range @p 0 - @p 9, otherwise @p 0
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

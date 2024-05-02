/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:39:01 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/06 15:37:19 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_toupper.c
 * @dontinclude ft_toupper.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Convert lowercase letter to corresponding uppercase letter
 * 
 * @param[in] c Character to convert
 * @retval int If @p c is a lowercase letter character, returns the integer
 * representation of the corresponding uppercase letter character, otherwise
 * returns @p c.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

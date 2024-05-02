/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:41:03 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/06 15:37:16 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 * @dontinclude ft_tolower.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Convert uppercase letter to corresponding lowercase letter
 * 
 * @param[in] c Character to convert
 * @retval int If @p c is an uppercase letter character, returns the integer
 * representation of the corresponding lowercase letter character, otherwise
 * returns @p c.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

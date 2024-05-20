/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 00:00:09 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/15 23:40:30 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_striteri.c
 * @dontinclude ft_striteri.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Applies function @p f to each character of string @p s
 * 
 * This function iterates from end to start
 * 
 * @param[in, out] s Null-terminated string to iterate over
 * @param[in] f Pointer to a function where the first and second arguments are
 * the index of the current character and a pointer to the current character
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	len;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (len--)
		f(len, s + len);
}

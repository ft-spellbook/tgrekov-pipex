/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:09:57 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:24:35 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_front_bonus.c
 * @dontinclude ft_lstadd_front_bonus.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Insert @ref s_list "node" @p new into the start of the list pointed
 * to by the pointer at @p lst.
 * 
 * If @p lst or @p new are @p NULL, does nothing.  
 * Sets @ref s_list::next "next" property of @ref s_list "node" at pointer
 * @p new to address at pointer @p lst and sets pointer at @p lst to @p new
 * 
 * @param[in,out] lst Pointer to pointer to first @ref s_list "node"
 * in the list.
 * @param[in] new Pointer to the new @ref s_list "node" to add
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

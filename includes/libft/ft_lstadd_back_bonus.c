/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:25:47 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:24:36 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_back_bonus.c
 * @dontinclude ft_lstadd_back_bonus.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Adds @ref s_list "node" at pointer @p new to the end of
 * the list starting at pointer pointed to by @p lst.
 * 
 * If @p lst is @p NULL, does nothing.  
 * If pointer at @p lst is @p NULL, sets pointer at @p lst to @p new.  
 * Otherwise sets @ref s_list::next "next" property of the last
 * @ref s_list "node" in the list to @p new
 * 
 * @param[in, out] lst Pointer to pointer to first @ref s_list "node"
 * in the list.
 * @param[in] new Pointer to the new @ref s_list "node" to add
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

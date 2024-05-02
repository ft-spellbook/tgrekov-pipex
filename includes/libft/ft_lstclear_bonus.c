/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:38:22 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/20 19:21:31 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstclear_bonus.c
 * @dontinclude ft_lstclear_bonus.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Delete every @ref s_list "node" in a list
 * along with it's @ref s_list::content "content"
 * 
 * @param[in, out] lst Pointer to a pointer to the first @ref s_list "node"
 * in the list
 * @param[in] del Function used to properly handle the deletion of the
 * @ref s_list "node"'s @ref s_list::content "content"
 */
void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

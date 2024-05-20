/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:50:13 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/20 19:22:20 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstmap_bonus.c
 * @dontinclude ft_lstmap_bonus.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Iterate over a list and create a new one from the results of applying
 * @p f to the @ref s_list::content "content" of each @ref s_list "node"
 * 
 * @param[in] lst Pointer to the starting @ref s_list "node"
 * @param[in] f Function which takes the @ref s_list::content "content" of the
 * current @ref s_list "node" and returns the @ref s_list::content "content"
 * for the new @ref s_list "node"
 * @param[in] del Function used to properly handle deletion of each
 * @ref s_list "node"'s @ref s_list::content "content"
 * in the new list, should allocation fail
 * @retval t_list* Pointer to the first @ref s_list "node" in the new list
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*new;
	void	*new_content;

	if (!lst)
		return (0);
	lst2 = 0;
	while (lst)
	{
		new_content = f(lst->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			if (del)
				del(new_content);
			ft_lstclear(&lst2, del);
			return (0);
		}
		ft_lstadd_back(&lst2, new);
		lst = lst->next;
	}
	return (lst2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:08:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/05/02 10:51:23 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	**arr_cut(void **arr, int len);
void	**arr_free(void **arr);
int		arr_has(void **arr, int len, void *content,
			int (*compare)(void *, void *));
int		arr_len(void **arr);
void	**dedupe(void **arr, int len,
			int (*compare)(void *, void *),
			void *(*copy)(void *));
void	*err(const char *str, void *retval);

#endif
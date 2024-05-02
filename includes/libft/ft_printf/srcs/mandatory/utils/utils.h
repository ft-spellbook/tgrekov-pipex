/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:32:00 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/11 23:52:37 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "internal_types.h"

int	u_len_base(t_ubiggest n, int base);
int	u_put_base(t_ubiggest n, char *base, int fd);
int	wrap_err(int n, int *total);

#endif
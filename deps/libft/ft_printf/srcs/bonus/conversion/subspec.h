/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subspec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:20:17 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 06:52:53 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSPEC_H
# define SUBSPEC_H

typedef enum e_lenmod
{
	none	= 0,
	hh		= 1,
	h		= 2,
	l		= 3,
	ll		= 4,
	j		= 5,
	z		= 6,
	t		= 7,
}	t_lenmod;

typedef struct s_subspec
{
	char		left_justify;
	char		*forced_sign;
	char		force_decimal;
	char		*pad_str;
	int			min_width;
	int			precision;
	t_lenmod	lenmod;
}	t_subspec;

#endif
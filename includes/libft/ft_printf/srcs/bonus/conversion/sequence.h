/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:46:53 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/13 06:56:24 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEQUENCE_H
# define SEQUENCE_H

# include <unistd.h>
# include "subspec.h"
# include "../utils/internal_types.h"

typedef struct s_sequence
{
	char				specifier;
	t_subspec			subspec;
	char				*sign;
	t_ubiggest			data;
	int					total_len;
	int					pad_len;
	int					(*process)(struct s_sequence, int *, int);
}	t_sequence;

#endif
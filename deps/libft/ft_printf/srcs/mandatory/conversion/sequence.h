/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:46:53 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/11 23:41:34 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEQUENCE_H
# define SEQUENCE_H

# include <unistd.h>
# include "../utils/internal_types.h"

typedef struct s_sequence
{
	char				specifier;
	char				*sign;
	t_ubiggest			data;
	int					total_len;
	int					(*process)(struct s_sequence, int *, int);
}	t_sequence;

#endif
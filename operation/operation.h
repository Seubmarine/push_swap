/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:09:38 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 14:25:30 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

enum e_op
{
	op_rot_rot = -5,
	op_swap_a = -4,
	op_push_a = -3,
	op_rev_rot_a = -2,
	op_rev_rot_b = -1,
	op_nothing = 0,
	op_rot_b = 1,
	op_rot_a = 2,
	op_push_b = 3,
	op_swap_b = 4,
	op_rev_rot_rot = 5,
	op_swap_swap = 6,
};

typedef struct s_op_vector
{
	size_t		len;
	size_t		capacity;
	enum e_op	*array;
	void		*to_free;
}	t_op_vector;

int		op_vector_init(t_op_vector *vec, size_t capacity, void *to_free);
void	op_vector_push_back(t_op_vector *vec, enum e_op current);
void	op_vector_free(t_op_vector *vec);
void	op_vector_applyf(t_op_vector *vec, void (*func)(enum e_op));
void	op_vector_grow(t_op_vector *vec);
void	op_print(enum e_op op);
#endif
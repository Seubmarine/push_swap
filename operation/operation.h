/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:09:38 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/29 23:46:39 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H
# define OPERATION_OPTIMISATION 1
# define DEBUG 0
# include <stddef.h>
# include <stdlib.h>

enum e_op
{
    rot_rot = -5,
    swap_a = -4,
    push_a = -3,
    rev_rot_a = -2,
    rev_rot_b = -1,
    no_op = 0,
    rot_b = 1,
    rot_a = 2,
    push_b = 3,
    swap_b = 4,
    rev_rot_rot = 5,
    swap_swap = 6,
};

typedef struct s_op_vector
{
    size_t len;
    size_t capacity;
    enum e_op *array;
} t_op_vector;

int op_vector_init(t_op_vector *vec, size_t capacity);
void op_vector_push_back(t_op_vector *vec, enum e_op current);
void op_vector_free(t_op_vector *vec);
void op_vector_applyf(t_op_vector *vec, void (*func)(enum e_op));
# include <stdio.h>
void op_print(enum e_op op);
#endif
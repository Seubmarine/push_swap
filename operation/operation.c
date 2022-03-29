/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:36:19 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/29 23:47:34 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

// return 0 on failure
int op_vector_init(t_op_vector *vec, size_t capacity)
{
	vec->array = malloc(sizeof(*(vec->array)) * capacity);
	if (vec->array == NULL)
		return (0);
	vec->capacity = capacity;
	vec->len = 0;
	return (1);
}

void op_vector_free(t_op_vector *vec)
{
	vec->len = 0;
	free(vec->array);
}

void op_vector_applyf(t_op_vector *vec, void (*func)(enum e_op))
{
	size_t i;

	i = 0;
	while (i < vec->len)
	{
		func(vec->array[i]);
		i++;
	}
}

void op_print(enum e_op op)
{
#if DEBUG
	const char *string_op[12] = {"rot_rot", "swap_a", "push_a", "rev_rot_a", "rev_rot_b", "no_op", "rot_b",
								 "rot_a", "push_b", "swap_b", "rev_rot_rot", "swap_swap"};
#else
	const char *string_op[12] = {"rr", "sa", "pa", "rra", "rrb", "no_op", "rb",
								 "ra", "pb", "sb", "rrr", "ss"};
#endif
	const char *t = string_op[op + 5];

	printf("%s\n", t);
}
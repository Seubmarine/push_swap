/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:36:19 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/17 14:27:07 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

// return 0 on failure
int	op_vector_init(t_op_vector *vec, size_t capacity)
{
	vec->array = malloc(sizeof(*(vec->array)) * capacity);
	if (vec->array == NULL)
		return (0);
	vec->capacity = capacity;
	vec->len = 0;
	return (1);
}

void	op_vector_free(t_op_vector *vec)
{
	vec->len = 0;
	free(vec->array);
}

void	op_vector_applyf(t_op_vector *vec, void (*func)(enum e_op))
{
	size_t	i;

	i = 0;
	while (i < vec->len)
	{
		func(vec->array[i]);
		i++;
	}
}

void	op_print(enum e_op op)
{
	const char		*string_op[12] = {"rr\n", "sa\n", "pa\n", "rra\n", "rrb\n",
					"no_op\n", "rb\n", "ra\n", "pb\n", "sb\n", "rrr\n", "ss\n"};
	const size_t	size_op[12] = {3, 3, 3, 4, 4, 6, 3, 3, 3, 3, 4, 3};

	write(1, string_op[op + 5], size_op[op + 5]);
}

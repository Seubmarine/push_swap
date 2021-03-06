/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_optimisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:40:35 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 18:27:39 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void	_op_vector_remove_double(t_op_vector *vec, enum e_op current)
{
	if (current == op_swap_swap)
		vec->len--;
	else if (current == op_rot_a || current == op_rot_b)
		vec->len--;
	else if (current == op_rev_rot_a || current == op_rev_rot_b)
		vec->len--;
	else if (current == op_push_a || current == op_push_b)
		vec->len--;
	else if (current == op_rot_rot || current == op_rev_rot_rot)
		vec->len--;
}

// return 1 if a merge as occured
static enum e_op	_op_vector_merge_double(enum e_op current, \
	enum e_op previous)
{
	if ((current == op_swap_a && previous == op_swap_b) || \
		(current == op_swap_b && previous == op_swap_a))
		return (op_swap_swap);
	if ((current == op_rot_a && previous == op_rot_b) || \
		(current == op_rot_b && previous == op_rot_a))
		return (op_rot_rot);
	else if ((current == op_rev_rot_a && previous == op_rev_rot_b) \
		|| (current == op_rev_rot_b && previous == op_rev_rot_a))
		return (op_rev_rot_rot);
	return (op_nothing);
}

void	op_vector_grow(t_op_vector *vec)
{
	enum e_op	*tmp;

	if (vec->len + 1 > vec->capacity)
	{
		tmp = malloc(sizeof(*tmp) * (vec->capacity * 2));
		if (tmp == NULL)
		{
			free(vec->to_free);
			op_vector_free(vec);
			exit(EXIT_FAILURE);
		}
		ft_memcpy(tmp, vec->array, sizeof(*vec->array) * vec->len);
		free(vec->array);
		vec->array = tmp;
		vec->capacity *= 2;
	}
}

void	op_vector_push_back(t_op_vector *vec, enum e_op current)
{
	enum e_op	previous;
	enum e_op	new_current_if_merge;

	if (vec->len > 0)
	{
		previous = vec->array[vec->len - 1];
		new_current_if_merge = _op_vector_merge_double(current, previous);
		if (new_current_if_merge)
		{
			vec->len--;
			op_vector_push_back(vec, new_current_if_merge);
			return ;
		}
		if (current + previous == 0)
		{
			_op_vector_remove_double(vec, current);
			return ;
		}
	}
	op_vector_grow(vec);
	vec->array[vec->len] = current;
	vec->len++;
}

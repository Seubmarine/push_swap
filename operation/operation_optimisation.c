/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_optimisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:40:35 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/29 23:44:58 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

#if OPERATION_OPTIMISATION
static void _op_vector_remove_double(t_op_vector *vec, enum e_op current)
{
	if (current == swap_swap)
		vec->len--;
	else if (current == rot_a || current == rot_b)
		vec->len--;
	else if (current == rev_rot_a || current == rev_rot_b)
		vec->len--;
	else if (current == push_a || current == push_b)
		vec->len--;
	else if (current == rot_rot || current == rev_rot_rot)
		vec->len--;
}

// return 1 if a merge as occured
static enum e_op _op_vector_merge_double(t_op_vector *vec, enum e_op current, enum e_op previous)
{
	if ((current == swap_a && previous == swap_b) || (current == swap_b && previous == swap_a))
		return (swap_swap);
	if ((current == rot_a && previous == rot_b) || (current == rot_b && previous == rot_a))
		return (rot_rot);
	else if ((current == rev_rot_a && previous == rev_rot_b) || (current == rev_rot_b && previous == rev_rot_a))
		return (rev_rot_rot);
	return (no_op);
}
#endif

void op_vector_push_back(t_op_vector *vec, enum e_op current)
{
	enum e_op previous;
	enum e_op new_current_if_merge;

    #if OPERATION_OPTIMISATION
	if (vec->len > 0)
	{
		previous = vec->array[vec->len - 1];
		new_current_if_merge = _op_vector_merge_double(vec, current, previous);
		if (new_current_if_merge)
		{
			vec->len--;
			op_vector_push_back(vec, new_current_if_merge);
			return;
		}
		if (current + previous == 0)
		{
			_op_vector_remove_double(vec, current);
			return;
		}
	}
    #endif
	vec->array[vec->len] = current;
	vec->len++;
}

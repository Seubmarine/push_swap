/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:30:40 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/30 00:42:44 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operation.h"

//print "r+name_of_stack" and rotate stack up
void	rot(t_stack *stack)
{
	op_vector_push_back(stack->operations, stack->op_rot);
	rotate(&stack->list);
}

//print "rr" and rotate the two stack up;
void	rot_rot(t_stack *stack0, t_stack *stack1)
{
	op_vector_push_back(stack0->operations, op_rot_rot);
	rotate(&stack0->list);
	rotate(&stack1->list);
}

//print "rr+name_of_stack" and rotate stack down
void	rot_rev(t_stack *stack)
{
	op_vector_push_back(stack->operations, stack->op_rot_rev);
	rotate_reverse(&stack->list);
}

//print "rrr" and rotate the two stack down
void	rot_rot_rev(t_stack *stack0, t_stack *stack1)
{
	op_vector_push_back(stack0->operations, op_rev_rot_rot);
	rotate_reverse(&stack0->list);
	rotate_reverse(&stack1->list);
}

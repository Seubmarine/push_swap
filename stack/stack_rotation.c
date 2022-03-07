/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:30:40 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/07 04:33:02 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack_operation.h"

//print "r+name_of_stack" and rotate stack up
void	rot(t_stack *stack)
{
	write(1, stack->str_rot, 3);
	rotate(&stack->list);
}

//print "rr" and rotate the two stack up;
void rot_rot(t_stack *stack0, t_stack *stack1)
{
	write(1, "rr\n", 3);
	rotate(&stack0->list);
	rotate(&stack1->list);
}
//print "rr+name_of_stack" and rotate stack down
void rot_rev(t_stack *stack)
{
	write(1, stack->str_rot_rev, 4);
	rotate_reverse(&stack->list);
}

//print "rrr" and rotate the two stack down
void rot_rot_rev(t_stack *stack0, t_stack *stack1)
{
	write(1, "rrr\n", 4);
	rotate_reverse(&stack0->list);
	rotate_reverse(&stack1->list);
}

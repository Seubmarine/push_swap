/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:43:23 by tbousque          #+#    #+#             */
/*   Updated: 2022/02/21 15:55:56 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operation.h"

void write_op(char *str, int strlen, char replace_char, int replace_pos)
{
	str[replace_pos] = replace_char;
	write(1, str, strlen);
}

//print "p+name_of_stack1" and push stack1 in stack0
void push(t_stack *stack0, t_stack *stack1)
{
	write_op("px\n", 3, stack0->name, 1);
	lstd_push(&stack0->list, &stack1->list);
}

//print "s+name_of_stack" and swap first two element of the stack
void swap(t_stack *stack)
{
	write_op("sx\n", 3, stack->name, 1);
	lstd_swap(&stack->list);
}

//print "ss" and swap first two element for each stack
void swap_swap(t_stack *stack0, t_stack *stack1)
{
	write(1, "ss\n", 3);
	lstd_swap(&stack0->list);
	lstd_swap(&stack1->list);
}

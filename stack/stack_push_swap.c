/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:43:23 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/30 00:42:22 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operation.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_b;
	const char	*src_b;

	src_b = src;
	dest_b = dest;
	i = 0;
	while (i < n)
	{
		dest_b[i] = src_b[i];
		i++;
	}
	return (dest);
}

t_stack	stack_init(char name, t_op_vector *vec_of_op)
{
	t_stack	stack;

	stack.list = NULL;
	stack.operations = vec_of_op;
	stack.name = name;
	if (stack.name == 'a')
	{
		stack.op_push = op_push_a;
		stack.op_swap = op_swap_a;
		stack.op_rot = op_rot_a;
		stack.op_rot_rev = op_rev_rot_a;
	}
	else if (stack.name == 'b')
	{
		stack.op_push = op_push_b;
		stack.op_swap = op_swap_b;
		stack.op_rot = op_rot_b;
		stack.op_rot_rev = op_rev_rot_b;
	}
	return (stack);
}

//print "p+name_of_stack1" and push stack1 in stack0
void	push(t_stack *stack0, t_stack *stack1)
{
	op_vector_push_back(stack0->operations, stack0->op_push);
	lstd_push(&stack0->list, &stack1->list);
}

//print "s+name_of_stack" and swap first two element of the stack
void	swap(t_stack *stack)
{
	op_vector_push_back(stack->operations, stack->op_swap);
	lstd_swap(&stack->list);
}

//print "ss" and swap first two element for each stack
void	swap_swap(t_stack *stack0, t_stack *stack1)
{
	op_vector_push_back(stack0->operations, op_swap_swap);
	lstd_swap(&stack0->list);
	lstd_swap(&stack1->list);
}

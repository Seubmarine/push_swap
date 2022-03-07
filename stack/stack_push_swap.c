/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:43:23 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/07 05:09:24 by tbousque         ###   ########.fr       */
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

t_stack stack_init(char name)
{
	t_stack stack;

	stack.list = NULL;
	stack.name = name;
	ft_memcpy(stack.str_push, "px\n", 3);
	ft_memcpy(stack.str_swap, "sx\n", 3);
	ft_memcpy(stack.str_rot, "rx\n", 3);
	ft_memcpy(stack.str_rot_rev, "rrx\n", 4);
	stack.str_push[1] = stack.name;
	stack.str_swap[1] = stack.name;
	stack.str_rot[1] = stack.name;
	stack.str_rot_rev[2] = stack.name;
	return (stack);
}

//print "p+name_of_stack1" and push stack1 in stack0
void push(t_stack *stack0, t_stack *stack1)
{
	write(1, stack0->str_push, 3);
	lstd_push(&stack0->list, &stack1->list);
}

//print "s+name_of_stack" and swap first two element of the stack
void swap(t_stack *stack)
{
	write(1, stack->str_swap, 3);
	lstd_swap(&stack->list);
}

//print "ss" and swap first two element for each stack
void swap_swap(t_stack *stack0, t_stack *stack1)
{
	write(1, "ss\n", 3);
	lstd_swap(&stack0->list);
	lstd_swap(&stack1->list);
}

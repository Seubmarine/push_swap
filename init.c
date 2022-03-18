/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/17 17:12:02 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list_double.h"
#include <stdio.h>

void print_stack(t_stack a, t_stack b)
{
	printf("A: ");
	test_next(a.list);
	printf("B: ");
	test_next(b.list);
}


int num_pos(t_stack *x, int n)
{
	t_list_double *current;
	current = x->list;
	while (n)
	{
		current = current->next;
		n--;
	}
	return (current->num);
}

int num(t_stack *x)
{
	return (x->list->num);
}

void push_back(t_stack *a, t_stack *b)
{
	push(a, b);
	rot(a);
}

void merge(t_stack *a, t_stack *b, int a_len, int b_len)
{
	//print_stack(*a, *b);
	while (a_len + b_len)
	{
		if (num(a) < num(b))
		{
			rot(a);
			a_len--;
		}
		else
		{
			push_back(a, b);
			b_len--;
		}
		if (!a_len || !b_len)
			break ;
	}
	while (b_len)
	{
		push_back(a, b);
		b_len--;
	}
	while (a_len)
	{
		rot(a);
		a_len--;
	}
	//print_stack(*a, *b);
}

#include <math.h>
int	algo(t_stack *a, t_stack *b, int len)
{
	int i = len / 2;
	while (i)
	{
		push(b, a);
		i--;
	}
	while (i < len / 4)
	{
		if (num(a) > num_pos(a, 1) && num(b) > num_pos(b, 1))
			swap_swap(a, b);
		else if (num(a) > num_pos(a, 1))
			swap(a);
		else if (num(b) > num_pos(b, 1))
			swap(b);
		rot_rot(a, b);
		rot_rot(a, b);
		i++;
	}
	
	//printf("setup finished\n");
	int num = len;
	int buk = 2;
	int j;
	int loop = 1;
	while (loop)
	{
		j = num / 2 / buk / 2;
		//printf("Bucket of size %i will execute %i times.\n", buk, j);
		if (j == 0)
		{
			merge(a, b, buk, buk);
			//print_stack(*a, *b);
			return (0);
		}
		while (j)
		{
			//print_stack(*a, *b);
			merge(a, b, buk, buk);
			if (!b->list)
				return (1);
			merge(b, a, buk, buk);
			j--;
		}
		buk *= 2;
	}
	/*
	print_stack(*a, *b);
	merge(a, b, 2, 2);
	merge(b, a, 2, 2);
	print_stack(*a, *b);
	merge(a, b, 4, 4);
	print_stack(*a, *b);
	*/
	return (0);
}


int	main(int argc, char **argv)
{
	t_list_double	*m_list_array;
	t_stack			stack_a;
	t_stack			stack_b;

	if (argc == 1)
		return (1);
	m_list_array = malloc(sizeof(*m_list_array) * (argc - 1));
	if (!m_list_array)
		return (1);
	stack_a = stack_init('a');
	stack_b = stack_init('b');
	stack_a.list = lstd_create(m_list_array, argc - 1, argv + 1);
	if (stack_a.list)
	{	
		algo(&stack_a, &stack_b, argc - 1);
	}
	//print_stack(stack_a, stack_b);
	free(m_list_array);
	return (0);
}

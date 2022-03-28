/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/28 22:50:05 by tbousque         ###   ########.fr       */
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


int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

//return middest value between a, b, c
int ft_mid(int a, int b, int c)
{
	const int min = ft_min(ft_min(a, b), c);
	const int max = ft_max(ft_max(a, b), c);
	return (a + b + c - max - min);
}

// hacky thing only work if all value are right after another
int get_median(t_stack *x, int len)
{
	t_list_double	*current;
	int		min;
	int		max;
	int		i;
	
	current = x->list;
	min = current->num;
	max = current->num;
	i = 0;
	while (i < len)
	{
		if (min > current->num)
			min = current->num;
		if (max < current->num)
			max = current->num;
		current = current->next;
		i++;
	}
	return (min + (max - min) / 2);
}

void	quick_sort_a(t_stack *a, t_stack *b, int len);

void	quick_sort_b(t_stack *a, t_stack *b, int len)
{
	int	i;
	int a_len;
	const int median = get_median(b, len);

	i = 1;
	a_len = 0;
	if (len <= 3)
	{
		while (len)
		{
			push(a, b);
			len--;
		}
		return ;
	}
	while (i <= len && b && num(b) != num_pos(b, 1))
	{
		if (num(b) < median + 1)
			rot(b);
		else
		{
			a_len++;
			push(a, b);
		}
		i++;
	}
	quick_sort_a(a, b, a_len);
	i = 0;
	while (i < len - a_len)
	{
		rot_rev(b);
		i++;
	}
	quick_sort_b(a, b, len - a_len);
}

void	quick_sort_a(t_stack *a, t_stack *b, int len)
{
	static int is_first_pass = 1;
	int	i;
	int b_len;
	const int median = get_median(a, len);

	i = 1;
	b_len = 0;
	if (len <= 3)
	{
		is_first_pass = 0;
		return ;
	}
	while (i <= len && a && num(a) != num_pos(a, 1))
	{
		if (num(a) > median)
			rot(a);
		else
		{
			b_len++;
			push(b, a);
		}
		i++;
	}
	i = 0;
	while (i < len - b_len && !is_first_pass)
	{
		rot_rev(a);
		i++;
	}
	quick_sort_a(a, b, len - b_len);
	quick_sort_b(a, b, b_len);
}


void	algo(t_stack *a, t_stack *b, int len)
{
	quick_sort_a(a, b, len);
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
		print_stack(stack_a, stack_b);
	}
	free(m_list_array);
	return (0);
}

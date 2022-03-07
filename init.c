/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/07 06:17:18 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list_double.h"

int	algo(t_stack *a, t_stack *b)
{	
	swap(a);
	push(b, a);
	push(b, a);
	push(b, a);
	rot_rot(a, b);
	rot_rot_rev(a, b);
	swap(a);
	push(a, b);
	push(a, b);
	push(a, b);
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
	algo(&stack_a, &stack_b);
	test_next(stack_a.list);
	free(m_list_array);
	return (0);
}

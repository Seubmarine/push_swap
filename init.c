/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/07 05:17:55 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list_double.h"

int main(int argc, char **argv)
{
	t_list_double *m_list_array;
	t_stack stack_a = stack_init('a');
	t_stack stack_b = stack_init('b');

	if (argc == 1)
		return (1);
	m_list_array = malloc(sizeof(*m_list_array) * (argc - 1));
	if (!m_list_array)
		return (1);
	stack_a.list = lstd_create(m_list_array, argc - 1, argv + 1);
	
	swap(&stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	rot_rot(&stack_a, &stack_b);
	rot_rot_rev(&stack_a, &stack_b);
	swap(&stack_a);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	

	test_next(stack_a.list);
	test_next(stack_b.list);
	free(m_list_array);
	return (0);
}

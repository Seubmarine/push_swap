/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/07 02:09:05 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list_double.h"

int main(int argc, char **argv)
{
	t_list_double *m_list_array;
	t_stack stack_a = {.list = NULL, .name = 'a'};
	t_stack stack_b = {.list = NULL, .name = 'b'};

	if (argc == 1)
		return (1);
	m_list_array = malloc(sizeof(*m_list_array) * (argc - 1));
	if (!m_list_array)
		return (1);
	stack_a.list = lstd_create(m_list_array, argc - 1, argv + 1);
	rot(&stack_a);
	//lstd_push_front(&stack_b, lstd_pop_front(&stack_a));
	//stack_swap(&stack_a);
	test_next(stack_a.list);
	test_next(stack_b.list);
	free(m_list_array);
	return (0);
}

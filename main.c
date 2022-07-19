/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:15:29 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/19 15:17:04 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	const size_t	num_count = get_total_arg_count(argc - 1, argv + 1);
	t_list_double	*m_list_array;
	t_stack			stack_a;
	t_stack			stack_b;
	t_op_vector		m_vec_op;

	m_list_array = create_and_verify_list(argc, argv, num_count);
	op_vector_init(&m_vec_op, 16, m_list_array);
	stack_a = stack_init('a', &m_vec_op);
	stack_b = stack_init('b', &m_vec_op);
	stack_a.list = m_list_array;
	quick_sort_a(&stack_a, &stack_b, num_count);
	op_vector_applyf(&m_vec_op, &op_print);
	op_vector_free(&m_vec_op);
	free(m_list_array);
}

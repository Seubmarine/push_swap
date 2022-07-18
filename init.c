/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 17:37:09 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	str_count_word(char *str)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			word_count++;
			while (str[i] != '\0' && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (word_count);
}

size_t	get_total_arg_count(int argc, char **argv)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < argc)
	{
		count += str_count_word(argv[i]);
		i++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_list_double	*m_list_array;
	t_op_vector		m_vec_op;
	t_stack			stack_a;
	t_stack			stack_b;

	if (argc == 1)
		return (EXIT_SUCCESS);
	size_t num_count = get_total_arg_count(argc - 1, argv + 1);
	m_list_array = malloc(sizeof(*m_list_array) * num_count);
	if (!m_list_array)
		return (EXIT_FAILURE);
	op_vector_init(&m_vec_op, 16, m_list_array);
	stack_a = stack_init('a', &m_vec_op);
	stack_b = stack_init('b', &m_vec_op);
	char **char_list = create_char_list(argc - 1, argv + 1, num_count);
	if (char_list == NULL)
	{
		op_vector_free(&m_vec_op);
		free(m_list_array);
		return (EXIT_FAILURE);
	}
	stack_a.list = lstd_create(m_list_array, num_count, char_list);
	free(char_list);
	if (stack_a.list == NULL)
	{
		write(1, "Error\n", 6);
		op_vector_free(&m_vec_op);
		free(m_list_array);
		exit(EXIT_FAILURE);
	}
	if (!sort_and_verify_arg(m_list_array, num_count))
	{
		write(1, "Error\n", 6);
		op_vector_free(&m_vec_op);
		free(m_list_array);
		return (EXIT_FAILURE);
	}
	if (stack_a.list)
	{
		quick_sort_a(&stack_a, &stack_b, num_count);
		op_vector_applyf(&m_vec_op, &op_print);
	}
	op_vector_free(&m_vec_op);
	free(m_list_array);
	return (0);
}

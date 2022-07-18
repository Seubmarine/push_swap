/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 18:18:23 by tbousque         ###   ########.fr       */
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

void	free_print_error_and_exit(void *to_free)
{
	if (to_free != NULL)
		free(to_free);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_list_double	*create_and_verify_list(int argc, char **argv)
{
	const size_t	num_count = get_total_arg_count(argc - 1, argv + 1);
	char			**char_list;
	t_list_double	*m_list_array;

	if (num_count == 0)
		exit(EXIT_SUCCESS);
	char_list = create_char_list(argc - 1, argv + 1, num_count);
	if (char_list == NULL)
		free_print_error_and_exit(NULL);
	m_list_array = malloc(sizeof(*m_list_array) * num_count);
	if (!m_list_array)
		free_print_error_and_exit(char_list);
	if (lstd_create(m_list_array, num_count, char_list) == NULL)
	{
		free(char_list);
		free_print_error_and_exit(m_list_array);
	}
	free(char_list);
	if (!sort_and_verify_arg(m_list_array, num_count))
		free_print_error_and_exit(m_list_array);
	return (m_list_array);
}

int	main(int argc, char **argv)
{
	t_list_double	*m_list_array;
	t_stack			stack_a;
	t_stack			stack_b;
	t_op_vector		m_vec_op;

	m_list_array = create_and_verify_list(argc, argv);
	op_vector_init(&m_vec_op, 16, m_list_array);
	stack_a = stack_init('a', &m_vec_op);
	stack_b = stack_init('b', &m_vec_op);
	stack_a.list = m_list_array;
	quick_sort_a(&stack_a, &stack_b, get_total_arg_count(argc - 1, argv + 1));
	op_vector_applyf(&m_vec_op, &op_print);
	op_vector_free(&m_vec_op);
	free(m_list_array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 17:15:42 by tbousque         ###   ########.fr       */
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

char	**create_char_list(int argc, char **argv, size_t num_count)
{
	char	**char_list;
	size_t	i;
	size_t	j;
	size_t	char_i;

	char_list = malloc(sizeof(*char_list) * num_count);
	if (char_list == NULL)
		return (NULL);
	if (num_count == (size_t)argc)
	{
		ft_memcpy(char_list, argv, sizeof(*argv) * argc);
		return (char_list);
	}
	j = 0;
	char_i = 0;
	while (num_count)
	{
		while ((*argv)[j] == ' ')
			j++;
		i = j;
		while ((*argv)[j] != ' ' && (*argv)[j] != '\0')
			j++;
		char_list[char_i++] = (*argv) + i;
		if ((*argv)[j] == '\0')
		{
			argv++;
			j = 0;
		}
		else
		{
			(*argv)[j] = '\0';
			j++;
		}
		num_count--;
	}
	return (char_list);
}

int	compar(const void *a, const void *b)
{
	const t_list_double	**ap = (void *)a;
	const t_list_double	**bp = (void *)b;

	return ((*ap)->num - (*bp)->num);
}

//Return NULL if error
//Will sort the list, find if theres any duplicate 
//and replace number by their sorted index for better median search
t_list_double	**create_sorted_list(t_list_double	*m_list_array, size_t num_count)
{
	t_list_double	**list_array_copy;
	size_t			i;

	list_array_copy = malloc(sizeof(*list_array_copy) * num_count);
	if (list_array_copy == NULL)
		return (NULL);
	i = 0;
	while (i < num_count)
	{
		list_array_copy[i] = &m_list_array[i];
		i++;
	}
	ft_qsort(list_array_copy, num_count, sizeof(*list_array_copy), compar);
	return (list_array_copy);
}

// return 1 on success 0 on error
int	sort_and_verify_arg(t_list_double	*m_list_array, size_t num_count)
{
	size_t			i;
	t_list_double	**list_array_copy;

	list_array_copy = create_sorted_list(m_list_array, num_count);
	if (list_array_copy == NULL)
		return (0);
	i = 0;
	while (i < num_count - 1)
	{
		if (list_array_copy[i]->num == list_array_copy[i + 1]->num)
		{
			free(list_array_copy);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < num_count)
	{
		list_array_copy[i]->num = i;
		i++;
	}
	free(list_array_copy);
	return (1);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 00:42:24 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_a(t_stack *a, t_stack *b, int len);

void	quick_sort_b(t_stack *a, t_stack *b, int len)
{
	int			i;
	int			a_len;
	const int	median = get_median(b, len);

	i = 1;
	a_len = 0;
	if (len == 3)
	{
		three_sort_b(a, b);
		return ;
	}
	if (len <= 2)
	{
		while (len)
		{
			push(a, b);
			len--;
		}
		if (num(a) > num_pos(a, 1))
			swap(a);
		return ;
	}
	if (b_is_sorted(b, len))
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
		if (num(b) <= median + 1)
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
	if (num_pos(b, len - a_len) != num(b))
	{
		while (i < len - a_len)
		{
			rot_rev(b);
			i++;
		}
	}
	quick_sort_b(a, b, len - a_len);
}

void	quick_sort_a(t_stack *a, t_stack *b, int len)
{
	int			i;
	int			b_len;
	const int	median = get_median(a, len);

	i = 1;
	b_len = 0;
	if (len == 3)
	{	
		three_sort_a(a, num(a), num_pos(a, 1), num_pos(a, 2));
		return ;
	}
	else if (len <= 2)
	{
		if (num(a) > num_pos(a, 1))
			swap(a);
		return ;
	}
	if (a_is_sorted(a, len))
		return ;
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
	if (num_pos(a, len - b_len) != num(a))
	{
		while (i < len - b_len)
		{
			rot_rev(a);
			i++;
		}
	}
	quick_sort_a(a, b, len - b_len);
	quick_sort_b(a, b, b_len);
}

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
	char	*str;

	char_list = malloc(sizeof(*char_list) * num_count);
	if (char_list == NULL)
		return (NULL);
	if (num_count == (size_t)argc)
	{
		ft_memcpy(char_list, argv, sizeof(*argv) * argc);
		return (char_list);
	}
	str = *argv;
	i = 0;
	j = 0;
	while (i < num_count)
	{
		while (str[j] == ' ')
			j++;
		char_list[i] = str + j;
		while (str[j] == '-' || (str[j] >= '0' && str[j] <= '9'))
			j++;
		if (str[j] == '\0')
		{
			j = 0;
			str = *(++argv);
		}
		else
		{
			str[j] = '\0';
			j++;
		}
		i++;
	}
	return (char_list);
}

int compar(const void *a, const void *b)
{
	const t_list_double **ap = (void *)a;
	const t_list_double **bp = (void *)b;

	return ((*ap)->num - (*bp)->num);
}

int	main(int argc, char **argv)
{
	t_list_double	*m_list_array;
	t_op_vector		m_vec_op;
	t_stack			stack_a;
	t_stack			stack_b;

	if (argc == 1)
		return (1);
	size_t num_count = get_total_arg_count(argc - 1, argv + 1);
	m_list_array = malloc(sizeof(*m_list_array) * num_count);
	if (!m_list_array)
		return (1);
	stack_a = stack_init('a', &m_vec_op);
	stack_b = stack_init('b', &m_vec_op);
	char **char_list = create_char_list(argc - 1, argv + 1, num_count);
	if (char_list == NULL)
	{
		free(m_list_array);
		return (EXIT_FAILURE);
	}
	stack_a.list = lstd_create(m_list_array, num_count, char_list);
	t_list_double **list_array_copy = malloc(sizeof(*list_array_copy) * num_count);
	for (size_t i = 0; i < num_count; i++)
	{
		list_array_copy[i] = &m_list_array[i];
	}
	ft_qsort(list_array_copy, num_count, sizeof(*list_array_copy), compar);
	for (size_t i = 0; i < num_count - 1; i++)
	{
		if (list_array_copy[i]->num == list_array_copy[i + 1]->num)
		{
			//TODO: FREE and exit program
			return (EXIT_FAILURE);
		}
	}
	for (size_t i = 0; i < num_count; i++)
	{
		list_array_copy[i]->num = i;
	}
	free(list_array_copy);
	op_vector_init(&m_vec_op, 20000); // TODO: grow dynamicly with time
	if (stack_a.list)
	{
		quick_sort_a(&stack_a, &stack_b, num_count);
		op_vector_applyf(&m_vec_op, &op_print);
	}
	op_vector_free(&m_vec_op);
	free(char_list);
	free(m_list_array);
	return (0);
}

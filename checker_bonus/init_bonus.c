/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:36:36 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/19 15:03:35 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

enum e_checker_err
{
	checker_malloc,
	no_arg,
	arg_is_incorrect,
	arg_is_duplicate,
	no_error,
};

typedef struct s_checker_result
{
	enum e_checker_err	err;
	t_list_double		*ok;
} t_checker_result;



t_checker_result	free_and_error(void *to_free, enum e_checker_err error, t_checker_result *result)
{
	if (to_free != NULL)
		free(to_free);
	result->err = error;
	result->ok = NULL;
	return (*result);
}

t_checker_result	create_and_verify_list_bonus(int argc, char **argv, 
	const size_t num_count)
{
	char				**char_list;
	t_list_double		*m_list_array;
	t_checker_result	result;

	result.err = no_error;
	if (num_count == 0)
		return(free_and_error(NULL, no_arg, &result));
	char_list = create_char_list(argc - 1, argv + 1, num_count);
	if (char_list == NULL)
		return(free_and_error(NULL, checker_malloc, &result));
	m_list_array = malloc(sizeof(*m_list_array) * num_count);
	if (!m_list_array)
		return(free_and_error(char_list, checker_malloc, &result));
	if (lstd_create(m_list_array, num_count, char_list) == NULL)
	{
		free(char_list);
		return(free_and_error(m_list_array, arg_is_incorrect, &result));
	}
	free(char_list);
	if (!sort_and_verify_arg(m_list_array, num_count))
		return(free_and_error(m_list_array, arg_is_duplicate, &result));
	result.ok = m_list_array;
	return (result);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && i < n - 1 && str1[i] && str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

//return 1 on correct input
int	process_input(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa", 2))
		swap(a);
	else if (!ft_strncmp(line, "sb", 2))
		swap(b);
	else if (!ft_strncmp(line, "ss", 2))
		swap_swap(a, b);
	else if (!ft_strncmp(line, "pa", 2))
		push(a, b);
	else if (!ft_strncmp(line, "pb", 2))
		push(b, a);
	else if (!ft_strncmp(line, "ra", 2))
		rot(a);
	else if (!ft_strncmp(line, "rb", 2))
		rot(b);
	else if (!ft_strncmp(line, "rra", 3))
		rot_rev(a);
	else if (!ft_strncmp(line, "rrb", 3))
		rot_rev(b);
	else if (!ft_strncmp(line, "rrr", 3))
		rot_rot_rev(a, b);
	else if (!ft_strncmp(line, "rr", 2))
		rot_rot(a, b);
	else
		return (0);
	return (1);
}

//return 1 on success 0 on error
int	checker(t_stack *a, t_stack *b, size_t num_count)
{
	char	*line;
	size_t	i;
	int is_error;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		is_error = !(process_input(line, a, b));
		free(line);
		if (is_error)
			return (0);
	}
	if (b->list != NULL)
		return (0);
	i = 0;
	while (a->list->num < a->list->next->num)
	{
		a->list = a->list->next;
		i++;
	}
	if (i < num_count - 1)
		return (0);
	return (1);
}

int main(int argc, char *argv[])
{
	const size_t			num_count = get_total_arg_count(argc - 1, argv + 1);
	const t_checker_result	result = create_and_verify_list_bonus(argc, argv, num_count);
	t_stack					stack_a;
	t_stack					stack_b;
	t_op_vector				m_vec_op;

	if (result.ok == NULL)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	op_vector_init(&m_vec_op, 16, result.ok);
	stack_a = stack_init('a', &m_vec_op);
	stack_b = stack_init('b', &m_vec_op);
	stack_a.list = result.ok;
	if (checker(&stack_a, &stack_b, num_count))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	op_vector_free(&m_vec_op);
	free(result.ok);
	return (EXIT_SUCCESS);
}

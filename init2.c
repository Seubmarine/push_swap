/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:29:55 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 17:37:58 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_char_list_part2(char	**char_list, char **argv, \
	size_t num_count)
{
	size_t	i;
	size_t	j;
	size_t	char_i;

	j = 0;
	char_i = 0;
	while (num_count--)
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
	}
}

char	**create_char_list(int argc, char **argv, size_t num_count)
{
	char	**char_list;

	char_list = malloc(sizeof(*char_list) * num_count);
	if (char_list == NULL)
		return (NULL);
	if (num_count == (size_t)argc)
	{
		ft_memcpy(char_list, argv, sizeof(*argv) * argc);
		return (char_list);
	}
	create_char_list_part2(char_list, argv, num_count);
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
static t_list_double	**create_sorted_list(t_list_double	*m_list_array, \
	size_t num_count)
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

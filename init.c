/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:33:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/29 17:42:22 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	test_next(t_list_double *l)
{
	t_list_double *first_chain;

	first_chain = l;
	printf("\ntest next : \n");
	while (1)
	{
		printf("%s\n", l->num);
		l = l->next;
		if (l == first_chain)
			break ;
	}
	return ;
}

void	test_prev(t_list_double *l)
{
	t_list_double *first_chain;
	
	first_chain = l;
	printf("\ntest prev : \n");
	while (1)
	{
		printf("%s\n", l->num);
		l = l->prev;
		if (l == first_chain)
			break ;
	}
}

void link_end(t_list_double *begin, t_list_double *end)
{
	begin->prev = end;
	begin->next = begin + 1;
	end->next = begin;
	end->prev = end - 1;
}

int main(int argc, char **argv)
{
	t_list_double	*m_array_list;
	t_list_double	*current_list;
	size_t			i;

	argc--;
	argv++;
	m_array_list = malloc(sizeof(*m_array_list) * argc);
	if (!m_array_list)
		return (1);
	link_end(m_array_list, &m_array_list[argc - 1]);
	m_array_list->num = argv[0];
	(&m_array_list[argc - 1])->num = argv[argc - 1];
	i = 1;
	while (i < argc - 1)
	{
		current_list = &m_array_list[i];
		current_list->next = &m_array_list[i + 1];
		current_list->num = argv[i];
		current_list->prev = &m_array_list[i - 1];
		i++;
	}
	test_next(m_array_list);
	test_prev(m_array_list);
	free(m_array_list);
	return (0);
}

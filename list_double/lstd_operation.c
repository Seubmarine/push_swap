/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:03:23 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/06 23:33:54 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_double.h"

void lstd_link(t_list_double *chain0, t_list_double *chain1)
{
	if (chain0)
		chain0->next = chain1;
	if (chain1)
		chain1->prev = chain0;
}

void	lstd_swap(t_list_double **stack)
{
	t_list_double	*first;
	t_list_double	*second;
	char			*mem_num;

	first = *stack;
	second = first->next;
	mem_num = first->num;

	first->num = second->num;
	second->num = mem_num;
}

t_list_double	*lstd_pop_front(t_list_double **stack)
{
	t_list_double	*poped;

	poped = *stack;
	if (poped == poped->next)
		*stack = NULL;
	else
	{
		lstd_link(poped->prev, poped->next);
		*stack = poped->next;
	}
	poped->next = NULL;
	poped->prev = NULL;
	return (poped);
}

void	lstd_push_front(t_list_double **list, t_list_double *pushed)
{
	if (!*list)
	{
		lstd_link(pushed, pushed);
	}
	else
	{
		lstd_link((*list)->prev, pushed);
		lstd_link(pushed, *list);
	}	
	*list = pushed;
}

void lstd_push(t_list_double **stack_a, t_list_double **stack_b)
{
	lstd_push_front(stack_a, lstd_pop_front(stack_b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:00:03 by tbousque          #+#    #+#             */
/*   Updated: 2022/02/21 13:01:50 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	test_next(t_list_double *l)
{
	t_list_double *first_chain;

	first_chain = l;
	if (!l)
	{
		printf("Stack empty!\n");
		return ;
	}
	printf("test next : \n");
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
	
	l = l->prev;
	first_chain = l;
	printf("test prev : \n");
	while (1)
	{
		printf("%s\n", l->num);
		l = l->prev;
		if (l == first_chain)
			break ;
	}
}

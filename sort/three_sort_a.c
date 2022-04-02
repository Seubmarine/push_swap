/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:18:06 by tbousque          #+#    #+#             */
/*   Updated: 2022/04/03 00:44:32 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	a_sort_cab(t_stack *x)
{
	swap(x);
	rot(x);
	swap(x);
	rot_rev(x);
	//printf("cab\n");
}

void	a_sort_bca(t_stack *x)
{
	rot(x);
	swap(x);
	rot_rev(x);
	swap(x);
	//printf("bca\n");
}

void	a_sort_bac(t_stack *x)
{
	swap(x);
	//printf("bac\n");
}

void	a_sort_cba(t_stack *x)
{
	swap(x);
	rot(x);
	swap(x);
	rot_rev(x);
	swap(x);
	//printf("cba\n");
}

void	a_sort_acb(t_stack *x)
{
	rot(x);
	swap(x);
	rot_rev(x);
	//printf("acb\n");
}
void three_sort_a(t_stack *x, int a, int b, int c)
{
	if (x->list->num == x->list->next->next->next->num)
		three_sort_alone_a(x);
	else if (a < b && b < c && c > a)
		return ;
	else if (a < b && b > c && c < a)
		a_sort_bca(x);
	else if (a > b && b > c && c < a)
		a_sort_cba(x);
	else if (a > b && b < c && c > a)
		a_sort_bac(x);
	else if (a > b && b < c && c < a)
		a_sort_cab(x);
	else if (a < b && b > c && c > a)
		a_sort_acb(x);
}
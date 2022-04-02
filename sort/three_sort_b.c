/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:50:33 by tbousque          #+#    #+#             */
/*   Updated: 2022/04/03 00:44:52 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	b_sort_cba(t_stack *a, t_stack *b)
{
	push(a, b);
    push(a, b);
    push(a, b);
}

void	b_sort_abc(t_stack *a, t_stack *b)
{
    rot(b);
	swap(b);
	push(a, b);
	push(a, b);
	rot_rev(b);
	push(a, b);
}

void	b_sort_cab(t_stack *a, t_stack *b)
{
    push(a, b);
    push(a, b);
    push(a, b);
    swap(a);
}

void	b_sort_bca(t_stack *a, t_stack *b)
{
	swap(b);
    b_sort_cba(a, b);
}

void	b_sort_bac(t_stack *a, t_stack *b)
{
	rot(b);
	swap(b);
	rot_rev(b);
	swap(b);
	push(a, b);
    push(a, b);
	push(a, b);
}

void	b_sort_acb(t_stack *a, t_stack *b)
{
	rot(b);
	push(a, b);
	push(a, b);
	rot_rev(b);
	push(a, b);
}

void three_sort_b(t_stack *a, t_stack *b)
{
	int ia = b->list->num;
	int ib = b->list->next->num;
	int ic = b->list->next->next->num;

	if (b->list->next->next->next->num == b->list->num)
		three_sort_alone_b(a, b);
	else if (ia < ib && ib < ic && ic > ia)
		b_sort_abc(a, b);
	else if (ia < ib && ib > ic && ic < ia)
		b_sort_bca(a, b);
	else if (ia > ib && ib > ic && ic < ia)
		b_sort_cba(a, b);
	else if (ia > ib && ib < ic && ic > ia)
		b_sort_bac(a, b);
	else if (ia > ib && ib < ic && ic < ia)
		b_sort_cab(a, b);
	else if (ia < ib && ib > ic && ic > ia)
		b_sort_acb(a, b);
}
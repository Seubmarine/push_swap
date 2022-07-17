/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_alone_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:41:40 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/17 16:27:01 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	b_sort_alone_abc(t_stack *b)
{
	rot(b);
	swap(b);
}

void	b_sort_alone_cab(t_stack *b)
{
	rot_rev(b);
	swap(b);
}

void	b_sort_alone_bca(t_stack *b)
{
	swap(b);
}

void	b_sort_alone_bac(t_stack *b)
{
	rot_rev(b);
}

void	three_sort_alone_b(t_stack *a, t_stack *b)
{
	const int	ia = b->list->num;
	const int	ib = b->list->next->num;
	const int	ic = b->list->next->next->num;

	if (ia < ib && ib < ic && ic > ia)
		b_sort_alone_abc(b);
	else if (ia < ib && ib > ic && ic < ia)
		b_sort_alone_bca(b);
	else if (ia > ib && ib < ic && ic > ia)
		b_sort_alone_bac(b);
	else if (ia > ib && ib < ic && ic < ia)
		b_sort_alone_cab(b);
	else if (ia < ib && ib > ic && ic > ia)
		rot(b);
	push(a, b);
	push(a, b);
	push(a, b);
}

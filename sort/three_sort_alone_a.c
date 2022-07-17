/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_alone_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:59:01 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/17 16:24:55 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	a_sort_alone_cba(t_stack *a)
{
	swap(a);
	rot_rev(a);
}

void	a_sort_alone_cab(t_stack *a)
{
	rot(a);
}

void	a_sort_alone_bca(t_stack *a)
{
	rot_rev(a);
}

void	a_sort_alone_acb(t_stack *a)
{
	rot(a);
	swap(a);
	rot_rev(a);
}

void	three_sort_alone_a(t_stack *a)
{
	const int	ia = a->list->num;
	const int	ib = a->list->next->num;
	const int	ic = a->list->next->next->num;

	if (ia < ib && ib > ic && ic < ia)
		a_sort_alone_bca(a);
	else if (ia > ib && ib > ic && ic < ia)
		a_sort_alone_cba(a);
	else if (ia > ib && ib < ic && ic > ia)
		swap(a);
	else if (ia > ib && ib < ic && ic < ia)
		a_sort_alone_cab(a);
	else if (ia < ib && ib > ic && ic > ia)
		a_sort_alone_acb(a);
}

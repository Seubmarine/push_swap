/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_alone_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:59:01 by tbousque          #+#    #+#             */
/*   Updated: 2022/04/03 00:44:22 by tbousque         ###   ########.fr       */
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

void	a_sort_alone_bac(t_stack *a)
{
    swap(a);
}

void	a_sort_alone_acb(t_stack *a)
{
    rot(a);
    swap(a);
	rot_rev(a);
}

void three_sort_alone_a(t_stack *a)
{
	int ia = a->list->num;
	int ib = a->list->next->num;
	int ic = a->list->next->next->num;
	
	if (ia < ib && ib > ic && ic < ia)
		a_sort_alone_bca(a);
	else if (ia > ib && ib > ic && ic < ia)
		a_sort_alone_cba(a);
	else if (ia > ib && ib < ic && ic > ia)
		a_sort_alone_bac(a);
	else if (ia > ib && ib < ic && ic < ia)
		a_sort_alone_cab(a);
	else if (ia < ib && ib > ic && ic > ia)
		a_sort_alone_acb(a);
}
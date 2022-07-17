/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:17:32 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 00:22:18 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sort.h"

int	num_pos(t_stack *x, int n)
{
	t_list_double	*current;

	current = x->list;
	while (n)
	{
		current = current->next;
		n--;
	}
	return (current->num);
}

int	num(t_stack *x)
{
	return (x->list->num);
}

// hacky thing only work if all value are right after another
// work because we sort all number with ft_qsort and replacing
// the number by their correct order
int	get_median(t_stack *x, int len)
{
	t_list_double	*current;
	int				min;
	int				max;
	int				i;

	current = x->list;
	min = current->num;
	max = current->num;
	i = 0;
	while (i < len)
	{
		if (min > current->num)
			min = current->num;
		if (max < current->num)
			max = current->num;
		current = current->next;
		i++;
	}
	return (min + (max - min) / 2);
}

int	a_is_sorted(t_stack *x, int len)
{
	int				i;
	t_list_double	*current;

	i = 0;
	current = x->list;
	while (i < (len - 1))
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

int	b_is_sorted(t_stack *x, int len)
{
	int				i;
	t_list_double	*current;

	i = 0;
	current = x->list;
	while (i < (len - 1))
	{
		if (current->num < current->next->num)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

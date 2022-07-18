/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:33:14 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 17:23:17 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sort.h"

void	quick_sort_a(t_stack *a, t_stack *b, int len);

void	quick_sort_b_part_2(t_stack *a, t_stack *b, int len);

void	quick_sort_b(t_stack *a, t_stack *b, int len)
{
	if (len == 3)
	{
		three_sort_b(a, b);
		return ;
	}
	if (len <= 2)
	{
		push_until(a, b, len);
		if (num(a) > num_pos(a, 1))
			swap(a);
		return ;
	}
	if (b_is_sorted(b, len))
	{
		push_until(a, b, len);
		return ;
	}
	quick_sort_b_part_2(a, b, len);
}

void	quick_sort_b_part_2(t_stack *a, t_stack *b, int len)
{
	int			i;
	int			a_len;
	const int	median = get_median(b, len);

	i = 1;
	a_len = 0;
	while (i <= len && b && num(b) != num_pos(b, 1))
	{
		if (num(b) <= median + 1)
			rot(b);
		else
		{
			a_len++;
			push(a, b);
		}
		i++;
	}
	quick_sort_a(a, b, a_len);
	i = 0;
	if (num_pos(b, len - a_len) != num(b))
	{
		rot_rev_until(b, len, a_len);
	}
	quick_sort_b(a, b, len - a_len);
}

void	quick_sort_a_part_2(t_stack *a, t_stack *b, int len);

void	quick_sort_a(t_stack *a, t_stack *b, int len)
{
	if (len == 3)
	{	
		three_sort_a(a, num(a), num_pos(a, 1), num_pos(a, 2));
		return ;
	}
	else if (len <= 2)
	{
		if (num(a) > num_pos(a, 1))
			swap(a);
		return ;
	}
	if (a_is_sorted(a, len))
		return ;
	quick_sort_a_part_2(a, b, len);
}

void	quick_sort_a_part_2(t_stack *a, t_stack *b, int len)
{
	int			i;
	int			b_len;
	const int	median = get_median(a, len);

	i = 1;
	b_len = 0;
	while (i <= len && a && num(a) != num_pos(a, 1))
	{
		if (num(a) > median)
			rot(a);
		else
		{
			b_len++;
			push(b, a);
		}
		i++;
	}
	i = 0;
	if (num_pos(a, len - b_len) != num(a))
	{
		rot_rev_until(a, len, b_len);
	}
	quick_sort_a(a, b, len - b_len);
	quick_sort_b(a, b, b_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:23:19 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 17:23:54 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sort.h"

void	push_until(t_stack *a, t_stack *b, int len)
{
	while (len)
	{
		push(a, b);
		len--;
	}
}

void	rot_rev_until(t_stack *x, int len, int stack_len)
{
	int	i;

	i = 0;
	while (i < len - stack_len)
	{
		rot_rev(x);
		i++;
	}
}

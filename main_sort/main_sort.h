/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:04:47 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 17:24:27 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_SORT_H
# define MAIN_SORT_H
# include "list_double.h"
# include "stack_operation.h"
# include "sort.h"

int		num_pos(t_stack *x, int n);
int		num(t_stack *x);
int		get_median(t_stack *x, int len);
int		a_is_sorted(t_stack *x, int len);
int		b_is_sorted(t_stack *x, int len);
void	quick_sort_a(t_stack *a, t_stack *b, int len);
void	quick_sort_b(t_stack *a, t_stack *b, int len);
void	push_until(t_stack *a, t_stack *b, int len);
void	rot_rev_until(t_stack *x, int len, int stack_len);

#endif
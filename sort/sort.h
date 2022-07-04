/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:42:57 by tbousque          #+#    #+#             */
/*   Updated: 2022/04/02 23:07:15 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "stack_operation.h"
# include "operation.h"

void	three_sort_alone_b(t_stack *a, t_stack *b);
void	three_sort_alone_a(t_stack *a);
void	three_sort_a(t_stack *x, int a, int b, int c);
void	three_sort_b(t_stack *a, t_stack *b);
#endif
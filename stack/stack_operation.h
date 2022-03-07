/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:56:13 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/07 01:11:30 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATION_H
# define STACK_OPERATION_H
# include <unistd.h>
# include "list_double.h"

typedef struct s_stack
{
	t_list_double *list;
	const char name;
}	t_stack;

//replace the char at pos by another one ("px\n", 3, 'b', 1) -> "pb\n"
void	write_op(char *str, int strlen, char replace_char, int replace_pos);

/* Operation */

//print "p+name_of_stack1" and push stack0 in stack1
void	push(t_stack *stack0, t_stack *stack1);

//print "s+name_of_stack" and swap first two element of the stack
void	swap(t_stack *stack);

//print "ss" and swap first two element for each stack
void	swap_swap(t_stack *stack0, t_stack *stack1);

//print "r+name_of_stack" and rotate stack up
void	rot(t_stack *stack);

//print "rr" and rotate the two stack up;
void	rot_rot(t_stack *stack0, t_stack *stack1);

//print "rr+name_of_stack" and rotate stack down
void	rot_rev(t_stack *stack);

//print "rrr" and rotate the two stack down
void	rot_rot_rev(t_stack *stack0, t_stack *stack1);

#endif

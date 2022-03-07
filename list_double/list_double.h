/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_double.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:14:46 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/07 06:08:28 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_DOUBLE_H
# define LIST_DOUBLE_H
# include <stddef.h>

typedef struct s_list_double
{
	struct s_list_double	*next;
	struct s_list_double	*prev;
	char					*num;
}	t_list_double;

void			lstd_link(t_list_double *chain0, t_list_double *chain1);
void			lstd_swap(t_list_double **stack);
t_list_double	*lstd_pop_front(t_list_double **stack);
void			lstd_push_front(t_list_double **list, t_list_double *pushed);
void			lstd_push(t_list_double **stack_a, t_list_double **stack_b);
void			rotate(t_list_double **list);
void			rotate_reverse(t_list_double **list);
t_list_double	*lstd_create(t_list_double *m_list_array, int n_arg, \
					char **char_list);
#endif

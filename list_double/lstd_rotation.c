/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:25:01 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/07 01:47:07 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_double.h"

void	rotate(t_list_double **list)
{
	if (!list || !*list)
		return ;
	t_list_double *lst = *list;
	*list = lst->next;
}

void	rotate_reverse(t_list_double **list)
{
	if (!list || !*list)
		return ;
	t_list_double *lst = *list;
	*list = lst->prev;
}

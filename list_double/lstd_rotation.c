/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:25:01 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/07 06:10:23 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_double.h"

void	rotate(t_list_double **list)
{
	if (!list || !*list)
		return ;
	*list = (*list)->next;
}

void	rotate_reverse(t_list_double **list)
{
	if (!list || !*list)
		return ;
	*list = (*list)->prev;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:56:29 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/19 14:30:58 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_double.h"

//argv point to first arg to use
t_list_double	*lstd_create(t_list_double *m_list_array, int n_arg, \
	char **char_list)
{
	t_list_double	*last;
	t_list_double	*current;
	int				i;
	long long		ll;
	char			*end;

	last = NULL;
	current = NULL;
	i = 0;
	while (i < n_arg)
	{
		current = &(m_list_array[i]);
		current->num_str = char_list[i];
		ll = ft_strtoll(char_list[i], &end, 10);
		if (*end || ll > INT_MAX || ll < INT_MIN || char_list[i] == end)
			return (NULL);
		current->num = (int) ll;
		lstd_link(last, current);
		last = current;
		i++;
	}
	while (current->prev)
		current = current->prev;
	lstd_link(last, current);
	return (current);
}

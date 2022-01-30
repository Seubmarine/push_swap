/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:22:59 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/29 15:49:25 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stddef.h>
typedef struct s_list_double
{
	struct s_list_double	*next;
	struct s_list_double	*prev;
	char					*num;
}	t_list_double;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:37:00 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/19 18:13:18 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include "get_next_line.h"

enum e_checker_err
{
	checker_malloc,
	no_arg,
	arg_is_incorrect,
	arg_is_duplicate,
	no_error,
};

typedef struct s_checker_result
{
	enum e_checker_err	err;
	t_list_double		*ok;
}	t_checker_result;

void	give_input_at_zero(size_t num_count);
#endif
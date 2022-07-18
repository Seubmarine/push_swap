/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:22:59 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 17:37:47 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stddef.h>
# include "list_double.h"
# include "libft.h"
# include "stack_operation.h"
# include "main_sort.h"
# include "sort.h"
# include "ft_qsort.h"
# include "main_sort.h"

char	**create_char_list(int argc, char **argv, size_t num_count);
int		sort_and_verify_arg(t_list_double	*m_list_array, size_t num_count);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_input_at_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:51 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/19 18:15:06 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	give_input_at_zero(size_t num_count)
{
	char	*line;

	if (num_count == 0)
	{
		line = get_next_line(STDIN_FILENO);
		if (line)
		{
			free(line);
			write(STDERR_FILENO, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else
		{
			write(STDOUT_FILENO, "Ok\n", 3);
			exit(EXIT_SUCCESS);
		}
	}
}

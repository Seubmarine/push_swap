/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 03:33:40 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/18 00:36:23 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

long long int	ft_strtoll(const char *nptr, char **endptr, int base);
void			*ft_memcpy(void *dest, const void *src, size_t n);
#endif

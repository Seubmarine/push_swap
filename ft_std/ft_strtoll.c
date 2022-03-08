/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 08:48:44 by tbousque          #+#    #+#             */
/*   Updated: 2022/03/08 04:28:23 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c -= 32;
	return (c);
}

int	ft_isspace(int c)
{
	return (c == '\n' || c == ' ' || c == '\f' || c == '\r' || c == '\t' || \
	c == '\v');
}

int	get_place_in_base(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (ft_isalpha(c))
		return (ft_tolower(c) - 97 + 10);
	return (-1);
}

long long int	ft_strtoll(const char *nptr, char **endptr, int base)
{
	size_t			i;
	int				neg;
	int				digit;
	long long int	value;

	value = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	neg = (nptr[i] == '-') * -2 + 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (1)
	{
		digit = get_place_in_base(nptr[i]);
		if (digit == -1 || digit >= base)
		{
			*endptr = (char *)nptr + i;
			return (value * neg);
		}
		value *= base;
		value += digit;
		i++;
	}
	return (value * neg);
}

/*
void main(void)
{
	char *end = NULL;
	char *str = "  -28";
	long long int n = strtoll(str, &end, 10);
	printf("%lli %p\n", n, end);
	long long int f = ft_strtoll(str, &end, 10);
	printf("%lli %p\n", f, end);
}*/

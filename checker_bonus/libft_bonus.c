/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:39:57 by tbousque          #+#    #+#             */
/*   Updated: 2022/07/19 11:55:21 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_strchr(const char *s, int c)
{	
	if (*s == (unsigned char) c)
		return ((char *)s);
	while (*s++)
		if (*s == (unsigned char) c)
			return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*s_ptr;

	s_ptr = s;
	while (*s++)
		;
	return ((size_t)(s - s_ptr - 1));
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - s1len < s2len)
	{
		str[i] = s2[i - s1len];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
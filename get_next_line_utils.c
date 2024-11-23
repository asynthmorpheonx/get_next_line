/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:55:37 by mel-mouh          #+#    #+#             */
/*   Updated: 2024/11/23 19:01:47 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_memcpy(char *dest, char *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*str;

	i = 0;
	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return ((char *)dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ((char *)malloc(ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

size_t	ft_strch(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

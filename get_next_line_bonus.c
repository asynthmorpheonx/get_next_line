/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:28:03 by mel-mouh          #+#    #+#             */
/*   Updated: 2024/11/27 00:47:15 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	free(s1);
	return (str);
}

static char	*extract_line(char **remainder, char *buffer)
{
	char	*line;
	char	*newline_pos;
	char	*new_remainder;

	newline_pos = ft_strchr(*remainder, '\n');
	if (buffer)
		free(buffer);
	if (newline_pos)
	{
		line = malloc((ft_strch(*remainder, '\n') + 2) * sizeof(char));
		ft_memcpy(line, *remainder, ft_strch(*remainder, '\n') + 1);
		new_remainder = ft_strjoin(NULL, newline_pos + 1);
		free(*remainder);
		*remainder = new_remainder;
	}
	else
	{
		line = ft_strjoin(NULL, *remainder);
		free(*remainder);
		*remainder = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainders[1024];
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		remainders[fd] = ft_strjoin(remainders[fd], buffer);
		if (ft_strchr(remainders[fd], '\n'))
			return (extract_line(&remainders[fd], buffer));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (remainders[fd] && *remainders[fd])
		return (extract_line(&remainders[fd], NULL));
	free(remainders[fd]);
	remainders[fd] = NULL;
	return (NULL);
}

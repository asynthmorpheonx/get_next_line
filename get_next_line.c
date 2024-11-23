/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:52:15 by mel-mouh          #+#    #+#             */
/*   Updated: 2024/11/23 19:09:47 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
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

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*newline_pos;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		while ((newline_pos = ft_strchr(remainder, '\n')))
		{
			line = malloc(bytes_read + 1);
			ft_memcpy(line, remainder, ft_strch(remainder, '\n') + 1);
			ft_memcpy(remainder, newline_pos + 1, ft_strlen(newline_pos + 1));
			free(buffer);
			return (line);
		}
		free(buffer);
	}
	free(buffer);
	if (remainder && *remainder)
	{
		line = ft_strdup(remainder);
		free(remainder);
		remainder = NULL;
		return (line);
	}
	free(remainder);
	remainder = NULL;
	return (NULL);
}
int main()
{
	int fd = open("test.txt", O_RDWR);
	char *c = get_next_line(fd);
	while (c)
	{
		printf("%s", c);
		free(c);
		c = get_next_line(fd);
	}
}

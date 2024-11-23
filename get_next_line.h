/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:06 by mel-mouh          #+#    #+#             */
/*   Updated: 2024/11/23 19:08:13 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_next_LINE_H
# define GET_next_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
char	*ft_memcpy(char *dest, char *src, size_t n);
size_t	ft_strch(const char *str, int c);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lafontai <lafontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 19:55:00 by lafontai          #+#    #+#             */
/*   Updated: 2020/05/07 17:16:29 by lafontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
void	read_file(char *buf, int *res, int n, int fd);
int		add_buf_to_line(char *buf, int n, char **line);
int		ft_strlen(char *str);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);

#endif

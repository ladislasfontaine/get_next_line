/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 19:55:00 by marvin            #+#    #+#             */
/*   Updated: 2020/04/01 20:00:07 by marvin           ###   ########.fr       */
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
int		add_buf_to_line(char *buf, int n, char **line);
int		ft_strlen(char *str);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
void	ft_strclr(char *s);

#endif

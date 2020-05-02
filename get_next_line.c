/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lafontai <lafontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 20:17:15 by lafontai          #+#    #+#             */
/*   Updated: 2020/05/02 16:48:50 by lafontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char static	buf[BUFFER_SIZE + 1];
	int static	n;
	int static	res;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	*line = (char *)malloc(sizeof(char));
	*line[0] = '\0';
	while (1)
	{
		if (n == 0)
			if ((res = read(fd, buf, BUFFER_SIZE)) >= 0)
				buf[res] = '\0';
		n += add_buf_to_line(buf, n, line);
		// mettre un if ( == -1)
		if (buf[n] == '\n' || res < BUFFER_SIZE)
			break ;
		if (n >= res)
			n = 0;
	}
	n += 1;
	if (!res || (res < BUFFER_SIZE && n > res))
		return (0);
	if (n >= res)
		n = 0;
	return (1);
}

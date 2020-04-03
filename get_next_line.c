/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 20:17:15 by marvin            #+#    #+#             */
/*   Updated: 2020/04/01 20:18:55 by marvin           ###   ########.fr       */
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
		if (n == 0) // si n = 0 c'est qu'on était à la fin du buffer
			if ((res = read(fd, buf, BUFFER_SIZE)) >= 0)
				buf[res] = '\0';
		n += add_buf_to_line(buf, n, line); // mettre un if ( == -1)
		if (buf[n] == '\n' || res < BUFFER_SIZE) // fin de la ligne ou fin du fichier
			break ;
		if (n >= res)
			n = 0;
	}
	n += 1;
	if (!res)
		return (0);
	if (n >= res)
		n = 0;
	return (1);
}

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	int		res;
	int		i;
	char	**line;

	line = (char **)malloc(sizeof(char *));
	res = 1;
	i = 1;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	while (res == 1)
	{
		res = get_next_line(fd, line);
		if (res != -1)
		{
			printf("Line %d : %s\n", i, *line);
			free(*line);
		}
		i++;
	}
	if (ac > 1)
		close(fd);
	free(line);
	//getchar();
	return (0);
}

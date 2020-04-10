#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		dst_len;
	size_t	i;

	dst_len = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[dst_len + i] = s2[i];
		i++;
	}
	s1[dst_len + i] = '\0';
	return (s1);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	ft_strclr(char *s)
{
	while (*s)
	{
		*s = '\0';
		s++;
	}
}

int		add_buf_to_line(char *buf, int n, char **line)
{
	char	*temp;
	int		i;
	
	i = 0;
	while (buf[n + i] && buf[n + i] != '\n')
		i++;
	temp = ft_strdup(*line);
	ft_strclr(*line);
	free(*line);
	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(temp) + i + 1))))
	{
		free(temp);
		return (0);
	}
	*line[0] = '\0';
	*line = ft_strncat(*line, temp, (size_t)ft_strlen(temp));
	*line = ft_strncat(*line, buf + n, (size_t)i);
	ft_strclr(temp);
	free(temp);

	return (i);
}

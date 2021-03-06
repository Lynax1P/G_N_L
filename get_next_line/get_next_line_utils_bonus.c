#include "get_next_line_bonus.h"

size_t	ft_strlen_join(char *str1, char *str2)
{
	size_t	j;
	size_t	i;

	if (!str1)
		return (0);
	j = 0;
	i = 0;
	if (str1)
	{
		while (str1[i] != 0)
		{
			j++;
			i++;
		}
	}
	i = 0;
	if (str2)
	{
		while (str2[i] != 0)
		{
			j++;
			i++;
		}
	}
	return (j);
}

char	*ft_strdup(char *str, int *n)
{
	char	*string;
	char	*point;
	size_t	i;

	if (!str)
		return (NULL);
	i = ft_strlen_join(str, NULL);
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
	{
		*n = -1;
		return (NULL);
	}
	point = string;
	while (*str != 0)
		*point++ = *str++;
	*point = 0;
	return (string);
}

char	*ft_join(char **line, char **buf)
{
	int		i;
	char	*string;
	char	*point;
	int		y;
	int		count;

	count = 0;
	if (!*line || ft_strlen_join(*line, NULL) == 0)
		return (ft_strdup(*buf, &count));
	i = ft_strlen_join(*line, *buf);
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	point = *line;
	y = 0;
	while (i--)
	{
		string[count++] = point[y++];
		if (point[y] == 0)
			y = 0;
		if (y == 0)
			point = *buf;
	}
	string[count] = 0;
	return (string);
}

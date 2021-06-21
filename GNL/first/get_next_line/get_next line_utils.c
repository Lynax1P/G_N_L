#include "get_next_line.h"

size_t	ft_strlen_join(char *str1, char *str2)
{
	size_t	j;
	size_t  i;

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

	if(!str)
		return(NULL);
	i = ft_strlen_join(str, NULL);
	string = malloc(sizeof(char) * (i + 1));
	if(!string)
	{
		*n = -1;
		return (NULL);
	}
	point = string;
	while(*str != 0)
		*point++ = *str++;
	*point = 0;
	return(string);
}

char	*ft_join(char **line, char **buf, int *n)
{
	int		i;
	char	*string;
	char	*point;
	int 	y;

	if (!*line || ft_strlen_join(*line, NULL))
		return (ft_strdup(*buf, n));
	i = ft_strlen_join(*line, *buf);
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
	{
		*n = -1;
		return (NULL);
	}
	point = *line;
	y = 0;
	while (i--)
	{
		string[*n++] = point[y++];
		if (point[y] == 0)
			y = 0;
		if (y == 0)
			point = *buf;
	}
	string[*n] = 0;
	return (string);
}
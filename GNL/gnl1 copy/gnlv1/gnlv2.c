#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc;	
	size_t	summ;
	char	*buff;

	if (nmemb == (size_t)0 && size == (size_t)0)
	{
		nmemb = 1;
		size = 1;
	}
	summ = size * nmemb;
	calloc = malloc(summ);
	if (!calloc)
		return (NULL);
	buff = (char *) calloc;
	while (summ-- != 0)
		*buff++ = 0;
	return (calloc);
}


char	*ft_strchr(char *line, char c)
{
	while (*line != 0)
	{
		if (*line == c)
			return (line);
		line++;
	}
	return (NULL);
}

size_t	ft_strlen_join(char *str1, char *str2)
{
	size_t	j;

	j = 0;
	if (str1)
		while (*str1++ != 0)
			j++;
	if (str2)
		while (*str2++ != 0)
			j++;
	return (j);
}

char	*ft_newstr(char *line, size_t i)
{
	char *str;

	if (ft_strlen_join(line, NULL) == 0)
		free(line);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	while (i != 0)
	{
		*str++ = '\0';
		i--;
	}
	*str = 0;
	return (str);
}

char	*ft_strdup(char *str, char *remainder)
{
	char	*string;
	char	*point;
	size_t	i;

	if(!str)
		return(NULL);
	i = ft_strlen_join(str, NULL);
	string = ft_calloc((i + 1), sizeof(char));
	if(!string)
		return (NULL);
	point = string;
	while(*str != 0)
		*point++ = *str++;
	*point = 0;
	if (remainder)
		free(remainder);
	return(string);
}

char	*ft_strjoin(char *line, char *str, char *frpt)
{
	size_t	i;
	char	*string;
	char	*p;

	if (!line)
		return (ft_strdup(str, NULL));
	if (!str)
		return (ft_strdup(line, NULL));
	i = ft_strlen_join(str, line);
	string = ft_calloc(i + 1, sizeof(char));
	if (!string)
		return (NULL);
	p = string;
	while(*line != 0)
		*p++ = *line++;
	while(*str != 0)
		*p++ = *str++;
	if (frpt)
		free(frpt);
	return (string);
}

int		check_remainder(char *remainder, char **line, int *coin)
{
	char	*point;
	char	*frpt;
	
	frpt = remainder;
	if (*line)
		free(*line);
	point = ft_strchr(remainder, '\n');
	if (point)
	{
		*point++ = 0;
		remainder = ft_strdup(point, NULL);
		*coin = 1;
	}
	*line = ft_strdup(frpt, frpt);
	return (*coin);
}

int		line_read(int fd, char **line, char *remainder, int *coin)
{
	char	*point;
	char	buff[10 + 1];
	ssize_t	count;
	char	*frpt;
	
	int BUFFER_SIZE = 10;
	if (*line)
		frpt = *line;
	while (*coin != 1 && count == BUFFER_SIZE)
	{
		count = read(fd, &buff, 10);
		if (count == -1)
			return (-1);
		buff[count] = 0;
		point = ft_strchr(buff, '\n');
		if (point)
		{
			*point++ = 0;
			remainder = ft_strdup(point, NULL);
			*coin = 1;
		}
		*line = ft_strjoin(*line, buff, frpt);
	}
	return (*coin);
}


int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	int			coinword;

	coinword = 0;
	if(read(fd, 0, 0) == -1 || !line)
		return (-1);
	if (*line)
		free(*line);
	if (remainder)
		check_remainder(remainder, &*line, &coinword);
	if (!coinword)
		return (line_read(fd, &*line, remainder, &coinword));
	return (coinword);
}

int		main()
{
	char	*line;
	int		fd;
	int		i;

	fd = open("keks.txt", O_RDWR);
	// printf("%d", fd);
	// if(fd)
	// {	
	// 	i = 0;

	// 	get_next_line(fd, &line);
	// 	printf("%s\n%d", line, i);
	// 	//free (line);
	// 	i++;
	// }
}

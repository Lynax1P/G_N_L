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

    if (ft_strlen_join(line, NULL) == 0)
        return (ft_strdup(str, line));
    if (ft_strlen_join(str, NULL) == 0)
        return (ft_strdup(line, line));
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

int		check_remainder(char **remainder, char **line, int *coin)
{
    char	*point;
    char	*frpt;

	if (ft_strlen_join(*remainder, NULL) == 0)
    frpt = *remainder;
    point = ft_strchr(*remainder, '\n');
    if (point)
    {
        *point++ = 0;
        *remainder = ft_strdup(point, NULL);
        *coin = 1;
    }
    *line = ft_strdup(frpt, frpt);
    if (*coin != 1)
        *coin = 3;
    return (*coin);
}

int BUFFER_SIZE = 1;

void	ft_point(char **point, char **remainder, int *coin)
{
	**point++ = 0;
	*remainder = ft_strdup(*point, *remainder);
	*coin = 1;
}

int		line_read(int fd, char **line, char **remainder, int *coin)
{
	char	*point;
	char	buff[1 + 1];
	ssize_t	count;
	char	*frpt;
	int		i;

	i = 0;
	count = BUFFER_SIZE;
	frpt = NULL;
    *remainder = NULL;
	while (*coin != 1 && (int)count == BUFFER_SIZE)
	{
		if (*line)
			frpt = *line;
		count = read(fd, &buff, BUFFER_SIZE);
		if (count == -1)
			return (-1);
		buff[count] = 0;
		point = ft_strchr(buff, '\n');
		if (point)
		{
			*point++ = 0;
            if(BUFFER_SIZE > 1)
			    *remainder = ft_strdup(point, *remainder);
			else
                remainder = ft_calloc(0, 0);
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
		if (read(fd, 0, 0) == -1 || !line || fd < 0)
			return (-1);
	*line = NULL;
    if (remainder)
        check_remainder(&remainder, &*line, &coinword);
    if (!coinword || coinword == 3)
	{
		if(line_read(fd, &*line, &remainder, &coinword) == 3)
			return (0);
		return (coinword);
	}
    return (coinword);
}

int		main()
{
    char	*line;
    int		fd;
    int		i;

    fd = open("keks.txt", O_RDWR);
    i = 1;
    printf("%d\n", fd);
	while(i != 0 && i != 3 && i != -1)
	{
		i = get_next_line(fd, &line);
	//	printf("%d\n", i);
		printf("%s\n", line);
		free(line);
	}
    // while (1)
    // {
    //     /* code */;
    // }
    
}

#include "get_next_line_bonus.h"

static	int	ft_delimiter(char **str1, char **str2)
{
	int	n;
	int	i;
	int	size;

	i = 0;
	n = 0;
	size = ft_strlen_join(*str1, NULL);
	while (*(*str1 + i) != 0)
	{
		if (*(*str1 + i) == '\n')
			n = 1;
		if (n == 1)
			*(*str1 + i) = 0;
		i++;
		if (n == 1)
			break ;
	}
	if (n > 0 && i < size)
		*str2 = ft_strdup(*str1 + i, &n);
	else
		*str2 = NULL;
	return (n);
}

static	ssize_t	ft_buffer(char **buf, int fd)
{
	ssize_t	n;

	n = 0;
	if (fd != -1)
	{
		n = read(fd, *buf, BUFFER_SIZE);
		if (n == -1)
			return (-1);
		*(*buf + n) = 0;
	}
	return (n);
}

static	int	line_read(int fd, char **line, char **ram)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	res;
	int		n;
	char	*point;
	char	*pline;

	res = (ssize_t)BUFFER_SIZE;
	n = 0;
	point = &(*buff);
	while (res == BUFFER_SIZE && n != 1)
	{
		res = ft_buffer(&point, fd);
		if (res == -1)
			return (-1);
		n = ft_delimiter(&point, ram);
		if (n == -1)
			return (-1);
		pline = *line;
		*line = ft_join(&*line, &point);
		if (!*line)
			return (-1);
		if (pline)
			free(pline);
	}
	return (!(res != BUFFER_SIZE && n == 0));
}

static	int	check_remainder(int fd, char **line, char **ram)
{
	int		n;
	char	*point;

	if (ft_strlen_join(*ram , NULL) == 0)
		return (line_read(fd, &*line, &*ram));
	point = *ram;
	n = ft_delimiter(ram, ram);
	if (n == -1)
		return (-1);
	*line = ft_join(&*line, &point);
	if (!*line)
		return (-1);
	if (point)
		free(point);
	if (n == 1)
		return (1);
	if (n == 0)
		return (line_read(fd, &*line, ram));
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*ram[10000];

	if (fd < 0 || read(fd, 0, 0) == -1 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (ram[fd])
		return (check_remainder(fd, &*line, &ram[fd]));
	return (line_read(fd, &*line, &ram[fd]));
}

// int main()
// {
// 	int fd = open("keks.txt", O_RDWR);
// 	int ds = open("lols.txt", O_RDWR);
// 	char	*line; 
// 	int i = 1;
// 	int j = 1;
// 
// 	while (i != 0 && j != 0)
// 	{
// 		if (i)
// 		{
// 			i = get_next_line(fd, &line);
// 			printf("%s\n", line);
// 			free(line);
// 		}
// 		if (j)
// 		{
// 			j = get_next_line(ds, &line);
// 			printf("%s\n", line);
// 			free(line);
// 		}
// 	}
// 	while (1)
// 	{
// 		/* code */
// 	}
// 
// }

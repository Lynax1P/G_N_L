#include "get_next_line.h"

int	ft_remainder(char **buf, char **ram)
{
	int	n;
	int	i;
	int	size;

	i = 0;
	n = 0;
	size = ft_strlen_join(*buf, NULL);
	while (*(*buf + i) != 0)
	{
		if (*(*buf + i) == '\n')
			n = 1;
		if (n == 1)
			*(*buf + i) = 0;
		i++;
		if (n == 1)
			break ;
	}
	if (n > 0 && i < size)
		*ram = ft_strdup(*buf + i, &n);
	else
		*ram = NULL;
	return (n);
}

ssize_t	ft_buffer(char **buf, int fd)
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

int	line_read(int fd, char **line, char **ram)
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
		n = ft_remainder(&point, ram);
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

int	check_remainder(int fd, char **line, char **ram)
{
	int		n;
	char	*point;

	point = *ram;
	n = ft_remainder(ram, ram);
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
	static char	*ram = NULL;

	if (fd < 0 || read(fd, 0, 0) == -1 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (ram)
		return (check_remainder(fd, &*line, &ram));
	return (line_read(fd, &*line, &ram));
}

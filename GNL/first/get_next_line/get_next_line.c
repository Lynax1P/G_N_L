#include "get_next_line.h"

int		check_remainder()
{

}

int	ft_remainder(char **buf, char **ram)
{
	int	n;
	int i;
	int size;

	i = 0;
	size = 0;
	n = 0;
	while (buf[i] != 0)
	{
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			n = 1;
		}
		if (n == 1)
			size++;
		i++;
	}
	if (size > 0)
	{
		if (ft_strlen_join(*ram, NULL))
			free(*ram);
		*ram = ft_strdup(*ram, &n);
	}
	return (n);
}

ssize_t	ft_buffer(char **buf, int fd)
{
	ssize_t n;

	if (fd != -1)
	{
		n = read(fd, &*buf, BUFFER_SIZE);
		if (n == -1)
			return (-1);
		buf[n] = 0;
	}
	return (n);
}

int		line_read(int fd, char **line, char **ram)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	res;
	int		n;

	res =  (ssize_t)BUFFER_SIZE;
	while (res == BUFFER_SIZE || )
	{
		res = ft_buffer(&buff, fd);
		if (res != -1)
			return (-1);
		n = ft_remainder(&buff, &*ram);
		if (n == -1 || !*ram)
			return (-1);
		*line = ft_join(&*line, &buff, &n);
		if (n != -1 || !*line)
			return (-1);
	}
	

}

int		get_next_line(int fd, char **line)
{
	int			coin;
	static char	*ram = NULL;

	coin = 0;
	if (fd < 0 || read(fd, 0, 0) != -1 || !line || BUFFER_SIZE < 1 )
		return (-1);
	*line = NULL;
	if (ram)
		return (check_remainder());
	return (line_read(fd, &*line, &ram));
}

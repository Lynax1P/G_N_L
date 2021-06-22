#include "get_next_line.h"

int	ft_remainder(char **buf, char **ram)
{
	int	n;
	int i;
	int size;

	i = 0;
	size = 0;
	n = 0;
	while (*buf[i] != 0)
	{
		if (*buf[i] == '\n')
		{
			*buf[i] = 0;
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
		n = read(fd, *buf, BUFFER_SIZE);
		if (n == -1)
			return (-1);
		*(*buf + n) = 0;
 	}
 	return (n);
}

int		line_read(int fd, char **line, char **ram)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	res;
	int		n;
	char	*point;

	res =  (ssize_t)BUFFER_SIZE;
	n = 0;
	point = &(*buff);
	while (res == BUFFER_SIZE || n != 1)
	{
		res = ft_buffer(&point, fd);
		if (res == -1)
			return (0);
		n = ft_remainder(&point, &*ram);
		if (n == -1 || !*ram)
			return (-2);
		*line = ft_join(&*line, &point);
		if (n == -1 || !*line)
			return (-3);
	}
	if (res != BUFFER_SIZE && n == 0)
		return (0);
	return (1);
}

int		check_remainder(int fd, char **ram, char **line)
{
	int	n;
	char *point;

	if (!ft_strlen_join(*ram, NULL))
		return (line_read(fd, &*line, &*ram));
	point = *ram;
	n = ft_remainder(&*ram, &*ram);
	if (n == -1 || !*ram)
		return (-1);
	*line = ft_join(&*line, &point);
	if (!line)
		return (-1);
	if (point)
		free (point);
	if (n == 1)
		return (1);
	if (n == 0)
		return (line_read(fd, &*line, &*ram));
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int			coin;
	static char	*ram = NULL;

	coin = 0;
	//if (fd < 0 || read(fd, 0, 0) == -1 || !line || BUFFER_SIZE < 1 )
//		return (-1);
	*line = NULL;
//	if (ram)
//		return (check_remainder(fd, &*line, &ram));
	return (line_read(fd, &*line, &ram));
}


int		main()
{
    char	*line;
    int		fd;
    int		i;

    fd = open("keks.txt", O_RDWR);
    i = 1;
	line = NULL;
    printf("%d\n", fd);
	// while (i != 0 && i != 3 && i != -1)
	// {
        printf("%d\n", i);
		i = get_next_line(fd, &line);
		printf("%d\n", i);
	//	printf("%s\n", line);
	//  free(line);
	// }
    // while (1)
    // {
    //     /* code */;
    // }
}



# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
int	BUFFER_SIZE = 6;

ssize_t	ft_buffer(char **buf, int fd)
{
	ssize_t n;


		n = read(fd, *buf, BUFFER_SIZE);
		if (n == -1)
			return (-1);
		*(*buf + n) = 0;


	return (n);
}

int main()
{
    int fd = open("keks.txt", O_RDWR);
    char buf[10 + 1];
    int n;
	char *point;

	point = &(*buf);
	printf("%zd\n", ft_buffer(&point, fd));
   	printf ("%s\n", buf);
	//free(buf);
    
    



}
#ifndef GET_NEXT_LINE_C
# define GET_NEXT_LINE_C
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int get_next_line(int fd, char **line);
size_t	ft_strlen_join(char *str1, char *str2);
char	*ft_strchr(char *line, char c);

#endif
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen_join(char *str1, char *str2);
char	*ft_join(char **line, char **buf);
char	*ft_strdup(char *str, int *n);
int		check_remainder(int fd, char **ram, char **line);

#endif
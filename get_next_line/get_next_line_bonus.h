#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// # define BUFFER_SIZE 3

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

size_t	ft_strlen_join(char *str1, char *str2);
char	*ft_join(char **line, char **buf);
char	*ft_strdup(char *str, int *n);

#endif
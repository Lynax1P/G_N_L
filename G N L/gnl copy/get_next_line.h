//
// Created by Chaos Sherill on 5/27/21.
//

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/** functions */
char	*ft_strchr(char *line, char c);
size_t	ft_strlen_join(char *str1, char *str2);
char	*ft_strjoin(char *line, char *str);
char	*ft_newstr(char *line, size_t i);
char	*ft_strdub(char *str, char *remainder);

#endif

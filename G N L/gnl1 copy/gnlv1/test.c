#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

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

    j = 0;
    if (str1)
        while (*str1++ != 0)
            j++;
    if (str2)
        while (*str2++ != 0)
            j++;
    return (j);
}

char	*ft_strjoin(char *line, char *str)
{
    size_t	j;
    char	*string;
    char	*p;

    j = 0;
    string = malloc(sizeof(char) * (ft_strlen_join(line, str) + 1));
    if (!string || !str)
        return (NULL);
    if  (!line)
        p = str;
    else
        p = line;
    while (p[j] != 0)
    {
        *string++ = p[j++];
        if (p[j] == 0 && p == line && str)
        {
            p = str;
            j = 0;
        }
    }
    *string = 0;
    if(ft_strlen_join(line, NULL))
        free (line);
    return (string - ft_strlen_join(line, str));
}

char	*ft_newstr(char *line, size_t i)
{
    char *str;

	if (ft_strlen_join(line, NULL))
    	free(line);
    str = malloc(i + 1);
    if (!str)
        return (NULL);
    while (i != 0)
    {
        *str++ = '\0';
        i--;
    }
    *str = 0;
    return (str);
}

char	*ft_strdub(char *str, char *remainder)
{
    char	*string;
    size_t	i;

    i = ft_strlen_join(str, NULL);
    string = malloc(sizeof(char) * (i + 1));

    while (*str != 0)
        *string++ = *str++;
    *string = 0;
    if (ft_strlen_join(remainder, NULL))
        free(remainder);
    return (string - i);
}

//char	*engin_line(char *line, char *remainder, int *fl)
//{
//    char	*p_t;
//    char	*str;
//
//    p_t = NULL;
//    fl = 0;
//    p_t = ft_strchr(remainder, '\n');
//    if (*p_t == '\n')
//    {
//        *p_t = 0;
//        *fl = 1;
//    }
//    line = ft_strjoin(line, remainder);
//    return (p_t);
//}


int main()
{
	char	*line;
	char	buff[5001];
	int		fl = 0;
	int		fd = open("/Users/csherill/Desktop/gnl1/keks.txt", O_RDWR);


		read(fd, buff, 5000);
		buff[5000] = 0;
		//printf("%s", buff);



		char	*p_t;
		char	*str;
		char	*remainder;

		remainder = buff;
		p_t = NULL;

		p_t = ft_strchr(remainder, '\n');
		if (*p_t == '\n')
		{
			*p_t = 0;
			fl = 1;
		}
		line = ft_strjoin(NULL, remainder);
		
	
	
	printf("%s", line);
	sleep(1000);



























	// char *lenf;
	// char lent[];
	// static char *word;
	// char	*p_t;
	// int	i;
	// static	char *remainder;

	// lenf = malloc(10);
	// i = 0;
	// while (i != 9)
	// {
	// 	lenf[i] = i + '0';
	// 	i++;
	// }
	// lenf[i] = '\0';
	// lenf = ft_newstr(lenf, 0);
	// p_t = engin_line(lenf, lent, 0);
	// if (*p_t == 0)
	// 	remainder = ft_strdub(++p_t, remainder, 0);

	// lenf = ft_newstr(lenf, 0);
	// p_t = ft_strchr(remainder, '\n');
	// if (*p_t == '\n')
	// {
	// 	*p_t = 0;
	// }
	// lenf = ft_strjoin(lenf, remainder, 0);
	// if(*p_t == 0)
	// 	remainder = ft_strdub(++p_t, remainder, 1);
	// printf("%s\n%s\n", lenf, remainder);
}

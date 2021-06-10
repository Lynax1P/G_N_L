#include <stdio.h>
#include "get_next_line.h"

int		main()
{
    char	*line;
    int		fd;
    int		i;

    fd = open("/Users/csherill/Desktop/gnl1/keks.txt", O_RDWR);
    i = 0;
   // printf("%d\n", fd);
    while(i != 2)
    {
        get_next_line(fd, &line);
        printf("%s\n", line);
        i++
    }
 //   sleep(1000);
   // printf("%d", fd);







//    char	*line;
//    char	buff[5001];
//    int		fl = 0;
//    int		fd = open("/Users/csherill/Desktop/gnl1/keks.txt", O_RDWR);
//
//
//    read(fd, buff, 5000);
//    buff[5000] = 0;
//    //printf("%s", buff);
//
//
//
//    char	*p_t;
//    char	*str;
//    char	*remainder;
//
//    remainder = buff;
//    p_t = NULL;
//
//    p_t = ft_strchr(remainder, '\n');
//    if (*p_t == '\n')
//    {
//        *p_t = 0;
//        fl = 1;
//    }
//    ft_newstr(line, 0);
//    line = ft_strjoin(NULL, remainder);
//
//
//
//    printf("%s", line);

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

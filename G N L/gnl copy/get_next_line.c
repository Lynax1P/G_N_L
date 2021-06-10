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
    if  (!ft_strlen_join(line, NULL))
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
    if(line)
        free(line);
    return (string - ft_strlen_join(line, str));
}

char	*ft_newstr(char *line, size_t i)
{
    char *str;

//    if (ft_strlen_join(line, NULL))
//        free(line);
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
    if (1)
        free(remainder);
    return (string - i);
}

char	*engin_line(char **line, char *remainder, int *fl)
{
    char	*p_t;
    char	*str;

    p_t = ft_strchr(remainder, '\n');
    if (p_t)
        if (*p_t == '\n')
        {
            *p_t = 0;
            *fl = 1;
        }
    *line = ft_strjoin(*line, remainder);
    return (p_t);
}


int		get_next_line(int fd, char **line)
{
    static char	*remainder;
    int			fl;
    char		*p_t;
    char 		buff[1+1];
    int         count;

    if (!line || read(fd, 0, 0) == -1)
        return (-1);
    *line = NULL;
    fl = 0;
    if (remainder)
    {
        p_t = engin_line(line, remainder, &fl);
        if (fl)
            remainder = ft_strdub(++p_t, remainder);
    }
    if (!fl)
    {
        while (!fl)
        {
            count = read(fd, buff, 1);
            buff[count] = '\0';
            p_t = engin_line(line, buff, &fl);
            //printf("%s\n", buff);
            if (fl)
                remainder = ft_strdub(++p_t, remainder);
        }
        if(!remainder)
            return (1);
        return (0);
    }
    if(!remainder)
        return (1);
    return (0);
}
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc;	
	size_t	sum;
	char	*buff;

	if (nmemb == (size_t)0 && size == (size_t)0)
	{
		nmemb = 1;
		size = 1;
	}
	summ = size * nmemb;
	calloc = malloc(sum);
	if (!calloc)
		return (NULL);
	buf	= (char *) calloc;
	while (summ-- != 0)
		*buff++ = 0;
	return (calloc);
}


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

char	*ft_newstr(char *line, size_t i)
{
	char *str;

	if (ft_strlen_join(line, NULL) == 0)
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

char	*ft_strdup(char *str, char *remainder)
{
	char	*string;
	char	*point;
	size_t	i;

	if(!str)
		return(NULL);
	i = ft_strlen_join(str, NULL);
	string = ft_calloc(sizeof(char) * (i + 1));
	if(!string)
		return (NULL);
	p = string;
	while(*str != 0)
		*p++ = *str++;
	*p = 0;
	if (remainder)
		free(remainder);
	return(string);
}

char	*ft_strjoin(char *line, char *str)
{
	size_t	i;
	char	*string;
	char	*p;

	if (!line)
		return (ft_strdup(str));
	if (!str)
		return (ft_strdup(line));
	i = ft_strlen_join(str, line)
	string = ft_calloc(i + 1, sizeof(char));
	if (!string)
		return (NULL);
	p = string;
	while(*line != 0)
		*p++ = *line++;
	while(*str != 0)
		*p++ = *str++;
	return (string);
}

int		line_read()
{

	
}
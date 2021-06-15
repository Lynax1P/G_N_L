/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:58:39 by csherill          #+#    #+#             */
/*   Updated: 2021/06/01 07:48:51 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	ft_strdup(char *line)
{
	size_t	i;
	char	*str;
	size_t	j;

	i = ft_strlen_join(line, NULL);
	j = i;
	str = malloc(sizeof(char) * (i + 1));
	while (i--)
		*str++ = *line++;
	*str = 0;
	free (line - j);
	return (str - j)
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:50:09 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/19 15:25:27 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	get_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	free_all(char **str)
{
	free (*str);
	*str = NULL;
}

static char	*fill_line(char **rem,	int a)
{
	char	*line;
	char	*tmp;
	int		index;

	tmp = NULL;
	index = get_line(*rem);
	if (a == 0 && *(*rem) == '\0')
		return (free_all(rem), NULL);
	else if ((*rem)[index] == '\n')
	{
		line = (char *)malloc(sizeof(char) * (index + 2));
		if (line == NULL)
			return (free_all(&line), NULL);
		ft_memcpy(line, *rem, index);
		line[index] = '\n';
		line[index + 1] = '\0';
		tmp = ft_strdup(*rem + index + 1);
		free(*rem);
		*rem = tmp;
		return (line);
	}
	line = ft_strdup(*rem);
	free_all(rem);
	return (line);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*buff;
	static char	*rem[1024];

	i = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (free_all(&buff), NULL);
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free_all(&buff), NULL);
		buff[i] = '\0';
		if (!rem[fd])
			rem[fd] = ft_strdup(buff);
		else
			rem[fd] = ft_strjoin(rem[fd], buff);
		if (get_line(rem[fd]) != -1)
			break ;
	}
	return (free_all(&buff), fill_line(&rem[fd], i));
}

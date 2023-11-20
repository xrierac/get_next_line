/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:04 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/20 12:33:15 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

char	*read_line(char *str, int fd)
{
	ssize_t	value;

	value = read(fd, str, BUFFER_SIZE);
	if (value <= 0)
		return (NULL);
	return (str);
}

int	find_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*new_line(char **storage, int fd, char *read_chunk)
{
	int		new_line_index;

	new_line_index = -1;
	while (new_line_index == -1)
	{
		new_line_index = find_new_line(storage[fd]);
		if (new_line_index == -1)
		{
			read_chunk = read_line(read_chunk, fd);
			if (read_chunk == NULL)
				return (NULL);
			storage[fd] = ft_strjoin(storage[fd], read_chunk);
//			printf("HOLA");
		}
		else
		{
			printf("%d", new_line_index);
			read_chunk = ft_substr(storage[fd], 0, (size_t)new_line_index + 1);
//			printf("%s", str);
			return (read_chunk);
		}
	}
	return (read_chunk);
}

char	*get_next_line(int fd)
{
	static char	*storage[FD_MAX + 1];
	char		*read_chunk;
	char		*line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (storage[fd] == 0)
		storage[fd] = ft_strdup("");
	read_chunk = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_chunk)
		return (NULL);
	line = new_line(storage, fd, read_chunk);
	if (line == NULL)
	{
		free(read_chunk);
		free(storage[fd]);
		return (NULL);
	}
	storage[fd] =  storage[fd] + ft_strlen(line) + BUFFER_SIZE;
	free(read_chunk);
	return (line);
}

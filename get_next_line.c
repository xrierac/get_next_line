/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:04 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/21 18:37:26 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
char	*next_line(int fd, char *read_return, char *cache)
{
	ssize_t	bytes_read;
	char	*tmp;

	while (!ft_strchr(cache, '\n'))
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(cache);
			return (NULL);
		}
		read_return[bytes_read] = 0;
		tmp = cache;
		cache = ft_strjoin(cache, read_return);
		free(tmp);
	}
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*read_return;
	char		*result;
	char		*tmp;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1 || !fd)
		return (NULL);
	read_return = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_return == NULL)
		return (NULL);
	if (cache == 0)
		cache = ft_strdup("");
	cache = next_line(fd, read_return, cache);
	if (cache == NULL)
	{
		free(read_return);
		return (cache);
	}
	result = ft_substr(cache, 0, ft_strchr(cache, '\n') - cache + 1);
	tmp = ft_strdup(ft_strchr(cache, '\n') + 1);
	free(cache);
	cache = tmp;
	free(read_return);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:04 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/22 14:06:01 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_line(int fd, char *read_return, char *cache)
{
	ssize_t	bytes_read;
	char	*tmp;

	while (!ft_strchr(cache, '\n'))
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read == 0 && *cache != '\0')
			return (cache);
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
	static char	*cache[FD_MAX];
	char		*read_return;
	char		*res;
	char		*tmp;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	read_return = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_return == NULL)
		return (NULL);
	if (cache[fd] == 0)
		cache[fd] = ft_strdup("");
	cache[fd] = next_line(fd, read_return, cache[fd]);
	free(read_return);
	if (cache[fd] == NULL || !ft_strchr(cache[fd], '\n'))
	{
		tmp = cache[fd];
		cache[fd] = 0;
		return (tmp);
	}
	res = ft_substr(cache[fd], 0, ft_strchr(cache[fd], '\n') - cache[fd] + 1);
	tmp = ft_strdup(ft_strchr(cache[fd], '\n') + 1);
	free(cache[fd]);
	cache[fd] = tmp;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:04 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/27 18:55:45 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_cache(char *cache, char *read_return, int fd)
{
	if (cache == NULL)
		cache = ft_strdup("");
	if (cache != NULL)
		cache = next_line(fd, read_return, cache);
	free(read_return);
	return (cache);
}

char	*free_mem(char *res, char *tmp)
{
	if (res)
		free(res);
	if (tmp)
		free(tmp);
	res = NULL;
	return (res);
}

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
		if (cache == NULL)
			return (NULL);
	}
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache[FD_MAX + 1];
	char		*read_return;
	char		*tmp;
	char		*res;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	read_return = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_return == NULL)
		return (NULL);
	cache[fd] = get_cache(cache[fd], read_return, fd);
	if (cache[fd] == NULL || !ft_strchr(cache[fd], '\n'))
	{
		tmp = cache[fd];
		cache[fd] = NULL;
		return (tmp);
	}
	res = ft_substr(cache[fd], 0, ft_strchr(cache[fd], '\n') - cache[fd] + 1);
	tmp = ft_strdup(ft_strchr(cache[fd], '\n') + 1);
	free(cache[fd]);
	if (res == NULL || tmp == NULL)
		res = free_mem(res, tmp);
	cache[fd] = tmp;
	return (res);
}

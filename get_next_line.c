/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:04 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/24 15:37:33 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*cache;
	char		*read_return;
	char		*tmp;
	char		*res;

	tmp = NULL;
	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	read_return = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_return == NULL)
		return (NULL);
	cache = get_cache(cache, read_return, fd);
	if (cache == NULL || !ft_strchr(cache, '\n'))
		res = cache;
	else
	{
		res = ft_substr(cache, 0, ft_strchr(cache, '\n') - cache + 1);
		tmp = ft_strdup(ft_strchr(cache, '\n') + 1);
		if (res == NULL || tmp == NULL)
			res = free_mem(res, tmp);
		free(cache);
	}
	cache = tmp;
	return (res);
}

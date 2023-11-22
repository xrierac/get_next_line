/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:04 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/22 15:02:54 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(int fd, char *read_return, char *cache)
{
	ssize_t	bytes_read;
	char	*tmp;

	if (cache == NULL)
		return (NULL);
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

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	read_return = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_return == NULL)
		return (NULL);
	if (cache == 0)
		cache = ft_strdup("");
	cache = next_line(fd, read_return, cache);
	free(read_return);
	if (cache == NULL || !ft_strchr(cache, '\n'))
	{
		tmp = cache;
		cache = 0;
		return (tmp);
	}
	read_return = ft_substr(cache, 0, ft_strchr(cache, '\n') - cache + 1);
	tmp = ft_strdup(ft_strchr(cache, '\n') + 1);
	free(cache);
	cache = tmp;
	return (read_return);
}

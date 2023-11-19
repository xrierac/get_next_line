/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:04 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/16 15:22:33 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *str, int fd)
{
	ssize_t	value;

	value = read(fd, str, BUFFER_SIZE);
	if (value <= 0)
		return (NULL);
	return (str);
}

int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*get_line(char *buffer)
{
	char	*str;
	int	new_line_index;

	new_line_index = find_newline(buffer); 
	if (new_line_index >= 0)
		return (ft_substr(buffer, 0, new_line_index + 1));
	else


char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX + 1];
	char		*read_chunk;
	char		*line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (*buffer[fd] == 0)
		*buffer[ft_strdup("")];
	read_chunk = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_chunk)
		return (NULL);

	return (line);
}

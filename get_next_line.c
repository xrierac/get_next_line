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

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD + 1];
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	if (*buffer[fd] == 0)
		*buffer[ft_strdup("")];
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	}
	line = get_line(buffer);
	while (line[ft_strlen(line) - 1] != '\n' && !line)
		buffer = read_file(buffer, fd);
		size_line = find_newline(buffer);
		if (size_line >= 0)
			line = get_line(buffer, size_line);	
	return (line);
}

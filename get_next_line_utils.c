/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:28:06 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/16 15:22:40 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *str, int fd)
{
	ssize_t	value;

	value = read(fd, str, BUFFER_SIZE);
	if (value <= 0)
		return (0);
	return(str);
}

int	find_new_line(char *s)
{
	int	i;

	i = 0;

ssize_t	find_newline(char *s)
{
	ssize_t	i;

	i = 0;
	while ((i <= BUFFER_SIZE && s[i] != '\n') || (i <= BUFFER_SIZE && !s[i]))
		i++;
	if (s[i] != '\0')
		return (i);
	return (-1);
}

char	*get_line(char *str)
{
	char	*line;

	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (0);
	



}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

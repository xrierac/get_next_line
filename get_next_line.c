/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:04 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/20 14:39:48 by xriera-c         ###   ########.fr       */
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

char	*next_line(int fd, char *temp)
{
	ssize_t	value;
	int		nl_index;
	char	*new_str;

	nl_index = -1;
	new_str = malloc(BUFFER_SIZE + 1);
	if (!new_str)
		return (NULL);
	while (nl_index == -1)
	{
		nl_index = find_new_line(temp);
		if (nl_index == -1)
		{
			value = read(fd, new_str, BUFFER_SIZE);
			if (value <= 0)
			{
				free(new_str);
				return (NULL);
			}
			temp = ft_strjoin(temp, new_str);
		}
		else
			free(new_str);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*cache[FD_MAX + 1];
	char		*read_return;
	char		*result;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	read_return = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_return == NULL)
		return (NULL);
	if (cache[fd] == 0)
		cache[fd] = ft_strdup("");
	return (result);
}

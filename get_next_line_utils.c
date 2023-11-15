/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:28:06 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/15 16:18:53 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_next_line_size(int fd)
{
	char	*c;
	size_t	i;

	i = 0;
	c = malloc(1);
	if (!c)
		return (0);
	while (!c)
	{
		i++;
		read(fd, c, 1);
		if (*c == '\n')
			break ;
	}
	free(c);
	return (i);
}

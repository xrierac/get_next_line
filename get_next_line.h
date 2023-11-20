/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:38:40 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/20 14:39:58 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

char	*get_next_line(int fd);
char	*read_file(char *str, int fd);
char	*new_line(char **storage, int fd, char *read_chunk);
int		find_new_line(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpu(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

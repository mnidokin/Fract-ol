/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 13:46:05 by mnidokin          #+#    #+#             */
/*   Updated: 2019/09/27 20:20:52 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_line(char **line, int fd, char **store, size_t *read_end)
{
	if ((*read_end = (ft_strchr(store[fd], '\n') > 0)))
		*line = ft_strsub(store[fd], 0,
				(size_t)(ft_strchr(store[fd], '\n') - store[fd]));
	else
		*line = ft_strdup(store[fd]);
}

char	*store_trim(char **store, int fd, char **line)
{
	char *res;

	res = ft_strsub(store[fd],
			(unsigned int)(ft_strlen(*line) + (ft_strchr(store[fd], '\n') > 0)),
			(size_t)(ft_strlen(store[fd]) -
			ft_strlen(*line) + (ft_strchr(store[fd], '\n') > 0)));
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static char	*store[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*to_del;
	ssize_t		read_b;
	size_t		read_end;

	if (fd > OPEN_MAX || fd < 0 ||
	!line || (!store[fd] && !(store[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(store[fd], '\n') &&
			(read_b = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_b] = '\0';
		to_del = store[fd];
		store[fd] = ft_strjoin(store[fd], buf);
		ft_strdel(&to_del);
	}
	if (read_b == -1 || !*(store[fd]))
		return ((read_b == -1) ? -1 : 0);
	add_line(line, fd, store, &read_end);
	to_del = store[fd];
	store[fd] = store_trim(store, fd, line);
	ft_strdel(&to_del);
	return (!(!(store[fd]) && !ft_strlen(*line)));
}

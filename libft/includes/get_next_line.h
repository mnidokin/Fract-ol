/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 13:46:16 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/21 22:49:47 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 16

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

int	get_next_line(const int fd, char **line);

#endif

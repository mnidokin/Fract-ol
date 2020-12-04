/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:54:10 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 02:07:02 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int ln;

	ln = (long int)n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln = ft_abs(ln);
	}
	if (ln >= 10)
	{
		ft_putnbr_fd((ln / 10), fd);
		ft_putnbr_fd((ln % 10), fd);
	}
	else
		ft_putchar_fd((ln + '0'), fd);
}

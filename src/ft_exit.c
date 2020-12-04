/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:12:13 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 04:12:15 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit(void *exit_par)
{
	(void)exit_par;
	exit(0);
}

int		ft_exit_help(void)
{
	ft_putendl("usage: ./fractol <fractal_name>");
	ft_putendl("available fractals: mandelbrot, julia, celtic perpendicular");
	return (0);
}

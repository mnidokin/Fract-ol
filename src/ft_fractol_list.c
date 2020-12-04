/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:12:57 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 04:16:08 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_fract *fract)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = ft_complex(fract->complex_num.re, fract->complex_num.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iter < fract->max_iteration)
	{
		z = ft_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + \
		fract->complex_num.re, 2.0 * z.re * z.im + fract->complex_num.im);
		iter++;
	}
	return (iter);
}

int	ft_julia(t_fract *fract)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = ft_complex(fract->complex_num.re, fract->complex_num.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iter < fract->max_iteration)
	{
		z = ft_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + \
		fract->julia_const.re, 2.0 * z.re * z.im + fract->julia_const.im);
		iter++;
	}
	return (iter);
}

int	ft_celtic_perpendicular(t_fract *fract)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = ft_complex(fract->complex_num.re, fract->complex_num.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iter < fract->max_iteration)
	{
		z = ft_complex(fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + \
		fract->complex_num.re, -2.0 * fabs(z.re) * z.im + \
		fract->complex_num.im);
		iter++;
	}
	return (iter);
}

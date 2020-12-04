/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_struct_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:12:53 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 04:36:31 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_complexnum_def(t_fract *fract)
{
	fract->max_iteration = MAX_ITER;
	fract->min = ft_complex(-2.0, -2.0);
	fract->max.re = 2.0;
	fract->max.im = fract->min.im + \
	(fract->max.re - fract->min.re) * HEIGHT / WIDTH;
	fract->julia_const = ft_complex(-0.4, 0.6);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:13:23 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 04:13:57 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_arrow_handler(int key, t_fract *fract)
{
	t_complex	offset;

	offset = ft_complex(ft_abs_float(fract->max.re - fract->min.re), \
	ft_abs_float(fract->max.im - fract->min.im));
	if (key == ARROW_LEFT)
	{
		fract->min.re -= offset.re * 0.05;
		fract->max.re -= offset.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		fract->min.re += offset.re * 0.05;
		fract->max.re += offset.re * 0.05;
	}
	else if (key == ARROW_UP)
	{
		fract->min.im += offset.im * 0.05;
		fract->max.im += offset.im * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		fract->min.im -= offset.im * 0.05;
		fract->max.im -= offset.im * 0.05;
	}
	ft_draw(fract);
}

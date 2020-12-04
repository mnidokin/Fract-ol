/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:13:19 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 12:13:57 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	ft_color_channel_gen(t_fract *fract, int iter)
{
	t_color	color;
	double	t;

	t = (double)iter / fract->max_iter;
	color.channel[COLOR] = 0;
	color.channel[(COLOR) % 3 + 1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(COLOR + 1) % 3 + 1] =
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(COLOR + 2) % 3 + 1] =
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

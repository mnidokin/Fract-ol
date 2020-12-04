/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_specific_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:12:37 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 04:12:37 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia_specific_handler(int x, int y, t_fract *fract)
{
	if (fract->julia_flag == 1)
	{
		fract->julia_const = ft_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		ft_draw(fract);
	}
	return (0);
}

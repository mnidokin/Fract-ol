/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:12:32 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 04:14:29 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_handler(int key, t_fract *fract)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == ARROW_LEFT || key == ARROW_RIGHT \
	|| key == ARROW_UP || key == ARROW_DOWN)
		ft_arrow_handler(key, fract);
	if (key == MAIN_PAD_SPACE)
		fract->julia_flag = fract->julia_flag * -1;
	return (0);
}

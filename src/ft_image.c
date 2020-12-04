/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:12:47 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 04:14:56 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	*ft_image(void *mlx)
{
	t_image		*image_struct;

	if (!(image_struct = (t_image *)malloc(sizeof(t_image))))
		exit(1);
	if (!(image_struct->image_mlx = mlx_new_image(mlx, WIDTH, HEIGHT)))
		exit(1);
	image_struct->data_addr = mlx_get_data_addr(image_struct->image_mlx, \
	&(image_struct->bits_per_pixel), &(image_struct->size_line), \
	&(image_struct->endian));
	return (image_struct);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:13:12 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 12:16:43 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_draw(t_fract *fract)
{
	pthread_t	threads[THREADS];
	t_fract		*fract_list;
	int			threads_count;

	if (!(fract_list = (t_fract *)malloc(sizeof(t_fract) * THREADS)))
		exit(1);
	ft_color_choose(fract);
	threads_count = 0;
	while (threads_count < THREADS)
	{
		ft_thread_set(&fract_list, fract, threads_count);
		if (pthread_create(&threads[threads_count], NULL, \
		(void *(*)(void *))ft_draw_thread, (void *)&fract_list[threads_count]))
			exit(1);
		threads_count++;
	}
	while (threads_count-- > 0)
		if (pthread_join(threads[threads_count], NULL))
			exit(1);
	mlx_put_image_to_window(fract->mlx_ptr, \
	fract->window, fract->image->image_mlx, 0, 0);
	free(fract_list);
	return (0);
}

void	ft_thread_set(t_fract **fract_list, t_fract *fract, int threads_count)
{
	(*fract_list)[threads_count] = *fract;
	(*fract_list)[threads_count].start = \
	threads_count * (HEIGHT / THREADS);
	(*fract_list)[threads_count].finish = \
	(threads_count + 1) * (HEIGHT / THREADS);
}

void	ft_draw_thread(t_fract *fract)
{
	int			y;
	int			x;
	t_color		pixel_color;

	y = fract->start;
	while (y < fract->finish)
	{
		fract->complex_num.im = fract->max.im - y * fract->color_pixel_depen.im;
		x = 0;
		while (x < WIDTH)
		{
			fract->complex_num.re = \
			fract->min.re + x * fract->color_pixel_depen.re;
			pixel_color = ft_color_channel_gen(fract, \
			fract->fract_discr_form(fract));
			ft_draw_pixel(fract, x, y, pixel_color);
			x++;
		}
		y++;
	}
}

int		ft_draw_pixel(t_fract *fract, int x, int y, t_color pixel_color)
{
	int	i;

	i = (x * fract->image->bpr / 8) + (y * fract->image->size_line);
	fract->image->data_addr[i] = pixel_color.channel[3];
	fract->image->data_addr[++i] = pixel_color.channel[2];
	fract->image->data_addr[++i] = pixel_color.channel[1];
	fract->image->data_addr[++i] = pixel_color.channel[0];
	return (0);
}

int		ft_color_choose(t_fract *fract)
{
	double re_val;
	double im_val;

	re_val = (fract->max.re - fract->min.re) / (WIDTH - 1);
	im_val = (fract->max.im - fract->min.im) / (HEIGHT - 1);
	fract->color_pixel_depen = ft_complex(re_val, im_val);
	return (0);
}

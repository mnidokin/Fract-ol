#include "fractol.h"

int	ft_draw(t_fract *fract)
{
	pthread_t	threads[THREADS];
	t_fract		fract_list[THREADS];
	int			threads_count;

	ft_color_choose(fract);
	threads_count = 0;
	while (threads_count < THREADS)
	{
		fract_list[threads_count] = *fract;
		fract_list[threads_count].start_line = threads_count * (HEIGHT / THREADS);
		fract_list[threads_count].finish_line = (threads_count + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[threads_count], NULL, (void *(*)(void *))ft_draw_thread, (void *)&fract_list[threads_count]))
			exit(1);
		threads_count++;
	}
	while (threads_count > 0)
	{
		threads_count--;
		if (pthread_join(threads[threads_count], NULL))
			exit(1);
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->window, fract->image->image_mlx, 0, 0);
	return (0);
}

void	ft_draw_thread(t_fract *fract)
{
	int			y;
	int			x;
	t_color		pixel_color;

	y = fract->start_line;
	while (y < fract->finish_line)
	{
		fract->complex_num.im = fract->max.im - y * fract->color_pixel_depen.im;
		x = 0;
		while (x < WIDTH)
		{
			fract->complex_num.re = fract->min.re + x * fract->color_pixel_depen.re;
			pixel_color = ft_color_channel_gen(fract, fract->fract_discr_form(fract));
			ft_draw_pixel(fract, x, y, pixel_color);
			x++;
		}
		y++;
	}
}

int	ft_draw_pixel(t_fract *fract, int x, int y, t_color pixel_color)
{
	int	i;

	i = (x * fract->image->bits_per_pixel / 8) + (y * fract->image->size_line);
	fract->image->data_addr[i] = pixel_color.channel[3];
	fract->image->data_addr[++i] = pixel_color.channel[2];
	fract->image->data_addr[++i] = pixel_color.channel[1];
	fract->image->data_addr[++i] = pixel_color.channel[0];
	return (0);
}

int	ft_color_choose(t_fract *fract)
{
	double re_val;
	double im_val;

	re_val = (fract->max.re - fract->min.re) / (WIDTH - 1);
	im_val = (fract->max.im - fract->min.im) / (HEIGHT - 1);
	fract->color_pixel_depen = ft_complex(re_val, im_val);
	return (0);
}

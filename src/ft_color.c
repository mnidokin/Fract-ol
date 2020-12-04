#include "fractol.h"

t_color	ft_color_channel_gen(t_fract *fract, int iter)
{
	t_color	color;
	double	t;

	t = (double)iter / fract->max_iteration;
	color.channel[0] = 0;
	color.channel[(0) % 3 + 1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1) % 3 + 1] =
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2) % 3 + 1] =
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

#include "fractol.h"

int				ft_scale(int key, int x, int y, t_fract *fract)
{
	t_complex	mouse_num;
	double		scaling_coef;
	double		scaling_val;

	if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
	{
		mouse_num = ft_complex(
			(double)x / (WIDTH / (fract->max.re - fract->min.re))
				+ fract->min.re,
			(double)y / (HEIGHT / (fract->max.im - fract->min.im))
				* -1 + fract->max.im);
		if (key == MOUSE_SCROLL_UP)
			scaling_coef = 0.80;
		else
			scaling_coef = 1.20;
		scaling_val = 1.0 / scaling_coef;
		fract->min.re = ft_scale_coord(mouse_num.re, fract->min.re, scaling_val);
		fract->min.im = ft_scale_coord(mouse_num.im, fract->min.im, scaling_val);
		fract->max.re = ft_scale_coord(mouse_num.re, fract->max.re, scaling_val);
		fract->max.im = ft_scale_coord(mouse_num.im, fract->max.im, scaling_val);
		ft_draw(fract);
	}
	return (0);
}

void	ft_scaling_map(t_fract *fract, t_complex mouse, double scaling_val)
{
	fract->min.re = ft_scale_coord(mouse.re, fract->min.re, scaling_val);
	fract->min.im = ft_scale_coord(mouse.im, fract->min.im, scaling_val);
	fract->max.re = ft_scale_coord(mouse.re, fract->max.re, scaling_val);
	fract->max.im = ft_scale_coord(mouse.im, fract->max.im, scaling_val);
}

double	ft_scale_coord(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

double ft_set_scale_val(int key)
{
	double		scaling_coef;
	double		res;

	if (key == MOUSE_SCROLL_UP)
			scaling_coef = 0.90;
	else
		scaling_coef = 1.10;
	res = 1.0 / scaling_coef;
	return (res);
}

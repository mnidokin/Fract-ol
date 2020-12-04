#include "fractol.h"

t_fract	*ft_fractol_init(void *mlx_ptr, char *fract_name)
{
	t_fract	*fract;

	if (!(fract = (t_fract *)malloc(sizeof(t_fract))))
		exit(1);
	fract->mlx_ptr = mlx_ptr;
	fract->julia_flag = 1;
	if (!(fract->window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, fract_name)))
		exit(1);
	fract->image = ft_image(mlx_ptr);
	ft_fractol_complexnum_def(fract);
	if (!(fract->fract_discr_form = ft_fractol_form(fract_name)))
		exit(1);
	ft_input_handler(fract, fract_name);
	return (fract);
}

void		ft_fractol_complexnum_def(t_fract *fract)
{
	fract->max_iteration = 50;
	fract->min = ft_complex(-2.0, -2.0);
	fract->max.re = 2.0;
	fract->max.im = fract->min.im + (fract->max.re - fract->min.re) * HEIGHT / WIDTH;
	fract->julia_const = ft_complex(-0.4, 0.6);
}

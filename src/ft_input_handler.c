#include "fractol.h"

int	ft_input_handler(t_fract *fract, char *fract_name)
{
	mlx_hook(fract->window, 2, 0, ft_key_handler, fract);
	mlx_hook(fract->window, 17, 0, ft_exit, fract);
	mlx_hook(fract->window, 4, 0, ft_scale, fract);
	if (ft_strequ(fract_name, "julia"))
		mlx_hook(fract->window, 6, 0, ft_julia_specific_handler, fract);
	return (0);
}

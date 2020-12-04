#include "fractol.h"

int	ft_julia_specific_handler(t_fract *fract, int x, int y)
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

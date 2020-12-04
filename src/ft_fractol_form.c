#include "fractol.h"

int	(*ft_fractol_form(char *name)) (t_fract *fract)
{
	size_t						iter;
	int							(*fract_discr_form)(t_fract *fract);
	static t_fract_discr_form	fract_list[] = {
		{ "mandelbrot", &ft_mandelbrot },
		{ "julia", &ft_julia },
		{ "celtic perpendicular", &ft_celtic_perpendicular },
	};

	iter = 0;
	fract_discr_form = NULL;
	while (iter < (sizeof(fract_list) / sizeof(t_fract_discr_form)))
	{
		if (ft_strequ(name, fract_list[iter].name))
			fract_discr_form = fract_list[iter].fract_discr_form;
		iter++;
	}
	return (fract_discr_form);
}

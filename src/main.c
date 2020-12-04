/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:12:20 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 05:03:27 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		(*ft_fractol_form(char *name)) (t_fract *fract)
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

t_fract	*ft_fractol_init(void *mlx_ptr, char *fract_name)
{
	t_fract	*fract;

	if (!(fract = (t_fract *)malloc(sizeof(t_fract))))
		exit(1);
	fract->mlx_ptr = mlx_ptr;
	fract->julia_flag = -1;
	if (!(fract->window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, fract_name)))
		exit(1);
	fract->image = ft_image(mlx_ptr);
	ft_fractol_complexnum_def(fract);
	if (!(fract->fract_discr_form = ft_fractol_form(fract_name)))
		exit(1);
	ft_input_handler(fract, fract_name);
	return (fract);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_fractol_form(av[1]))
		{
			ft_exit_help();
			return (0);
		}
		ft_av_fractol_handler(ac, av);
	}
	ft_exit_help();
	return (0);
}

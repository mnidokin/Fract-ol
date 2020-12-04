/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:13:01 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 04:13:01 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_av_fractol_handler(int ac, char **av)
{
	void		*mlx_ptr;
	t_fract		*fract_list;

	(void)ac;
	mlx_ptr = mlx_init();
	fract_list = ft_fractol_init(mlx_ptr, av[1]);
	ft_draw(fract_list);
	mlx_loop(mlx_ptr);
	return (0);
}

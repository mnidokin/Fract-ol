#include "fractol.h"

int	ft_av_fractol_handler(int ac, char **av)
{
	int			iter;
	void		*mlx_ptr;
	t_fract		**fract_list;

	iter = 0;
	mlx_ptr = mlx_init();
	if (!(fract_list = (t_fract **)malloc(sizeof(t_fract *) * 3)))
		exit(1);
	while (iter < ac)
	{
		fract_list[iter] = ft_fractol_init(mlx_ptr, av[iter]);
		ft_draw(fract_list[iter]);
		iter++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}

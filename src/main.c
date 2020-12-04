#include "fractol.h"

int	main(int ac, char **av)
{
	int	fract_num;

	fract_num = 1;
	if (ac < 2 || ac > 4)
	{
		exit(1);
	}
	while (fract_num++ < ac)
		if (!ft_fractol_form(av[fract_num]))
			break ;
	if (fract_num == ac)
		ft_av_fractol_handler(ac - 1, &av[1]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:23:46 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/04 15:02:19 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdint.h>
# include <stdlib.h>
# include <pthread.h>

# define COLOR	2

# define WIDTH		1000
# define HEIGHT		1000
# define THREADS	20
# define MAX_ITER  	100

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define MAIN_PAD_ESC		53
# define MAIN_PAD_SPACE		49
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_image
{
	void			*image_mlx;
	char			*data_addr;
	int				bpr;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_fract
{
	void			*mlx_ptr;
	void			*window;
	int				max_iter;
	int				julia_flag;
	int				start;
	int				finish;
	int				(*fract_discr_form)(struct s_fract*fractol);
	t_image			*image;
	t_complex		min;
	t_complex		max;
	t_complex		color_pixel_depen;
	t_complex		complex_num;
	t_complex		julia_const;
}					t_fract;

typedef struct		s_fract_discr_form
{
	char			*name;
	int				(*fract_discr_form)(t_fract *fractol);
}					t_fract_discr_form;

/*
** ft_abs_float.c
*/

float				ft_abs_float(float num);

/*
** ft_arrow_handler.c
*/

void				ft_arrow_handler(int key, t_fract *fract);

/*
** ft_complex.c
*/

t_complex			ft_complex(double re, double im);

/*
** ft_fractol_list.c
*/

int					ft_mandelbrot(t_fract *fract);
int					ft_julia(t_fract *fract);
int					ft_celtic_perpendicular(t_fract *fract);

/*
** ft_fractol_struct_init.c
*/

t_fract				*ft_fractol_init(void *mlx_ptr, char *fract_name);
void				ft_fractol_complexnum_def(t_fract *fract);

/*
** ft_image.c
*/

t_image				*ft_image(void *mlx);

/*
** ft_input_handler.c
*/

int					ft_input_handler(t_fract *fract, char *fract_name);

/*
** ft_fractol_handler.c
*/

int					ft_av_fractol_handler(int ac, char **av);

/*
** ft_draw.c
*/

int					ft_draw(t_fract *fract);
void				ft_draw_thread(t_fract *fract);
int					ft_color_choose(t_fract *fract);
int					ft_draw_pixel(t_fract *fract, int x, \
					int y, t_color pixel_color);
void				ft_thread_set(t_fract **fract_list, \
					t_fract *fract, int threads_count);

/*
** ft_color.c
*/

t_color				ft_color_channel_gen(t_fract *fract, int iter);

/*
**  ft_key_handler.c
*/

int					ft_key_handler(int key, t_fract *fract);

/*
** ft_scale.c
*/

int					ft_scale(int button, int x, int y, t_fract *fract);
void				ft_scaling_map(t_fract *fract, t_complex mouse, \
					double scaling_val);
double				ft_scale_coord(double start, double end, \
					double interpolation);
double				ft_set_scale_val(int key);

/*
** ft_exit.c
*/

int					ft_exit(void *exit_par);
int					ft_exit_help(void);

/*
** ft_julia_specific_handler.c
*/

int					ft_julia_specific_handler(int x, int y, t_fract *fract);

#endif

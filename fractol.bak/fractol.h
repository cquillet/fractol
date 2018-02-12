/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:23:54 by cquillet          #+#    #+#             */
/*   Updated: 2017/12/08 20:41:05 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include "float_2f.h"
# include "int_2d.h"
# include "complex.h"
# include "pixel.h"
# include "graphics.h"
# include "polynomial.h"
# include "box.h"

# ifndef NB_THREADS
#  define NB_THREADS 4
# endif

# ifndef COEFF_ZOOM
#  define COEFF_ZOOM 1.2
# endif

# ifndef FRACT_LIMITS
#  define FRACT_LIMITS
#  define FRACT_WIDTH 600
#  define FRACT_LEN_NAME 50
#  define NB_ITER_MIN 10
#  define NB_ITER_MAX 150
#  define NB_ITER_DELTA 5
#  define FRACT_POWER_MAX 8
#  define FRACT_WIDTH_MIN 6.e-16
#  define FRACT_WIDTH_MAX 500.
# endif

# ifndef FRACT_DISPLAY
#  define FRACT_DISPLAY
#  define NB_FRACT_COLORS 3
#  define NB_INFO_DISPLAY 3
# endif

# ifndef NB_TYPE_FRACT
#  define NB_TYPE_FRACT 4
#  define MANDELBROT 0
#  define JULIA 1
#  define BURNING 2
#  define NEWTON 3
#  define SIERPINSKI 4
# endif

# ifndef NB_POLY_NEWTON
#  define NB_POLY_NEWTON 5
# endif

typedef struct		s_fractal
{
	t_mlx			mlx;
	t_boxf			plane;
	t_box			win;
	int				fractal_type;
	int				newton_type;
	int				nb_fractal;
	int				nb_newton;
	int				color_id;
	char			display_info;
	unsigned int	power;
	int				thread_id;
	t_cplx			z0;
	t_cplx			c[NB_TYPE_FRACT];
	t_poly			poly_newton[NB_POLY_NEWTON];
	t_poly			poly_newton_deriv[NB_POLY_NEWTON];
	char			poly_names[NB_POLY_NEWTON][FRACT_LEN_NAME + 1];
	unsigned int	nb_iter_max;
	t_pixel			mouse;
	t_cplx			target;
	char			pause;
	t_2f			coeff;
	t_2f			coeff_zoom_in;
	t_2f			coeff_zoom_out;
	t_box			zoom;
	t_pixel			start_zoom;
	unsigned int	*save;
	char			buttons;
	char			zooming;
	char			key_shift;
	void			(*fract_init[NB_TYPE_FRACT])(struct s_fractal *f);
	unsigned int	(*fract_calc[NB_TYPE_FRACT])(struct s_fractal f, t_cplx z);
	char			name[NB_TYPE_FRACT][FRACT_LEN_NAME + 1];
	char			*dyn_fract;
}					t_fractal;

t_fractal			*init_fractal(t_fractal *f, t_mlx m);
t_cplx				pix_to_cplx(t_pixel p, t_fractal f);
int					fractal(t_fractal *f);
int					exit_fractol(t_fractal *f, int ret_value);
int					recenter(t_fractal *f, t_2f zoom);

void				mandel_init(t_fractal *f);
unsigned int		mandel_calc(t_fractal f, t_cplx z);

void				julia_init(t_fractal *f);
unsigned int		julia_calc(t_fractal f, t_cplx z);

int					init_poly_newton(t_fractal *f);
void				newton_init(t_fractal *f);
unsigned int		newton_calc(t_fractal f, t_cplx z);

unsigned int		burning_calc(t_fractal f, t_cplx z);
void				burning_init(t_fractal *f);

int					fract_key_press(int key, void *param);
int					fract_key_release(int key, void *param);
int					fract_mouse_move(int x, int y, void *param);
int					fract_mouse_release(int button, int x, int y, void *param);
int					fract_mouse_press(int button, int x, int y, void *param);

int					is_on_symbol(t_fractal f, t_pixel p);
void				show_info(t_fractal *f);

#endif

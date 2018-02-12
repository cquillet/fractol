/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:17:31 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 18:31:35 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "polynomial.h"
#include "libft.h"

static int		init_poly_newton1(t_fractal *f, int n)
{
	ft_strcpy(f->poly_names[n], "Newton P(z) = z3 - 1");
	f->poly_newton[n] = init_poly(3);
	poly_fill_nth_deg(&f->poly_newton[n], 0, create_complex(-1., 0.));
	f->poly_newton_deriv[n] = poly_derivative(f->poly_newton[n]);
	n++;
	ft_strcpy(f->poly_names[n], "Newton P(z) = z3 - 2z + 2");
	f->poly_newton[n] = init_poly(3);
	poly_fill_nth_deg(&f->poly_newton[n], 0, create_complex(2., 0.));
	poly_fill_nth_deg(&f->poly_newton[n], 1, create_complex(-2., 0.));
	f->poly_newton_deriv[n] = poly_derivative(f->poly_newton[n]);
	n++;
	ft_strcpy(f->poly_names[n], "Newton P(z) = z8 + 15z4 - 16");
	f->poly_newton[n] = init_poly(8);
	poly_fill_nth_deg(&f->poly_newton[n], 0, create_complex(-16., 0.));
	poly_fill_nth_deg(&f->poly_newton[n], 4, create_complex(15., 0.));
	f->poly_newton_deriv[n] = poly_derivative(f->poly_newton[n]);
	n++;
	return (n);
}

static int		init_poly_newton2(t_fractal *f, int n)
{
	ft_strcpy(
			f->poly_names[n], "Newton P(z) = z5 - (3i)z3 - (5+2i)z2 + 3z + 1");
	f->poly_newton[n] = init_poly(5);
	poly_fill_nth_deg(&f->poly_newton[n], 0, create_complex(1., 0.));
	poly_fill_nth_deg(&f->poly_newton[n], 1, create_complex(3., 0.));
	poly_fill_nth_deg(&f->poly_newton[n], 2, create_complex(-5., -2.));
	poly_fill_nth_deg(&f->poly_newton[n], 3, create_complex(0., -3.));
	f->poly_newton_deriv[n] = poly_derivative(f->poly_newton[n]);
	n++;
	ft_strcpy(f->poly_names[n], "Newton P(z) = z6 + z3 - 1");
	f->poly_newton[n] = init_poly(6);
	poly_fill_nth_deg(&f->poly_newton[n], 0, create_complex(-1., 0.));
	poly_fill_nth_deg(&f->poly_newton[n], 3, create_complex(1., 0.));
	f->poly_newton_deriv[n] = poly_derivative(f->poly_newton[n]);
	n++;
	return (n);
}

static void		init_fract_functions(t_fractal *f)
{
	int		type;

	type = MANDELBROT;
	f->fract_init[type] = &mandel_init;
	f->fract_calc[type] = &mandel_calc;
	ft_strcpy(f->name[type], "Mandelbrot");
	type = JULIA;
	f->fract_init[type] = &julia_init;
	f->fract_calc[type] = &julia_calc;
	f->c[type] = create_complex(0.285, 0.01);
	ft_strcpy(f->name[type], "Julia");
	let_bin(f->dyn_fract, type, 1);
	type = NEWTON;
	f->fract_init[type] = &newton_init;
	f->fract_calc[type] = &newton_calc;
	f->c[type] = create_complex(1., 0.);
	ft_strcpy(f->name[type], "Newton");
	type = BURNING;
	f->fract_init[type] = &burning_init;
	f->fract_calc[type] = &burning_calc;
	ft_strcpy(f->name[type], "Burning ship");
	f->nb_fractal = NB_TYPE_FRACT;
}

static void		init_zoom(t_fractal *f)
{
	f->zooming = 0;
	f->coeff = create_2f(COEFF_ZOOM, COEFF_ZOOM);
	f->coeff_zoom_out = create_2f(COEFF_ZOOM, COEFF_ZOOM);
	f->coeff_zoom_in = create_2f(1. / COEFF_ZOOM, 1. / COEFF_ZOOM);
}

t_fractal		*init_fractal(t_fractal *f, t_mlx m)
{
	if (!f)
		return (NULL);
	if (!(f->save = (unsigned int *)malloc(
							m.win.width * m.win.height * sizeof(unsigned int))))
		return (NULL);
	if (!(f->dyn_fract = create_tab_bin(NB_TYPE_FRACT)))
		return (NULL);
	f->win = create_box(0, m.win.width - 1, 0, m.win.height - 1);
	f->mlx = m;
	f->mouse = create_pixel(m.win.width / 2, m.win.height / 2, 0xFFFFFF);
	f->pause = 1;
	f->target = create_complex(0., 0.);
	f->buttons = 0;
	f->key_shift = 0;
	f->nb_newton = init_poly_newton1(f, 0);
	f->nb_newton = init_poly_newton2(f, f->nb_newton);
	f->power = 2;
	f->newton_type = 0;
	f->color_id = 0;
	f->display_info = 1;
	f->nb_iter_max = 35;
	init_zoom(f);
	init_fract_functions(f);
	return (f);
}

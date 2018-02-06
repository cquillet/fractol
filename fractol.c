/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:46:57 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 18:12:35 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "graphics.h"
#include "pixel.h"
#include "libft.h"
#include "float_2f.h"
#include "colors.h"
#include "libft.h"
#include "scale.h"
#include "polynomial.h"
#include <math.h>
#include "mlx.h"

t_cplx				pix_to_cplx(t_pixel p, t_fractal f)
{
	t_cplx			z;
	t_2f			win;
	t_2f			plane;

	win = create_2f(0., (t_re)box_width(f.win));
	plane = create_2f(f.plane.x_min, f.plane.x_max);
	z.re = scalef((t_re)p.x, win, plane);
	win = create_2f(0., (t_re)box_height(f.win));
	plane = create_2f(f.plane.y_min, f.plane.y_max);
	z.im = scalef((t_re)p.y, win, plane);
	return (z);
}

static unsigned int	frac_color(t_fractal f, unsigned int n)
{
	unsigned int	color1;

	if (n >= f.nb_iter_max)
		return (0);
	if (f.color_id == 0)
		color1 = spectrum_color(n, f.nb_iter_max, 0);
	else if (f.color_id == 1)
		color1 = spectrum_color(n, NB_ITER_MAX, 0);
	else if (f.color_id == 2)
		color1 = spectrum_gray(n, f.nb_iter_max, 0);
	else
		color1 = 0;
	return ((unsigned int)color1);
}

static int			color_pixel(t_pixel *p, t_fractal f)
{
	t_cplx			z;
	unsigned int	n;

	if (f.display_info && get_bin(f.dyn_fract, f.fractal_type)
														&& is_on_symbol(f, *p))
		p->color = 0xFFFFFF;
	else
	{
		z = pix_to_cplx(*p, f);
		n = f.fract_calc[f.fractal_type](f, z);
		p->color = frac_color(f, n);
	}
	return ((int)p->color);
}

static void			*fractal_thread(void *arg)
{
	t_pixel			p;
	t_fractal		*f;

	f = (t_fractal*)arg;
	p.y = 0;
	while (p.y % NB_THREADS != f->thread_id)
		p.y++;
	while (p.y < f->mlx.win.height)
	{
		p.x = 0;
		while (p.x < f->mlx.win.width)
		{
			color_pixel(&p, *f);
			put_pixel_in_img(f->mlx.mlx, (void *)&(f->mlx), p);
			p.x++;
		}
		p.y += NB_THREADS;
	}
	pthread_exit(0);
	return ((void *)f);
}

int					fractal(t_fractal *f)
{
	int				n;
	pthread_t		threads[NB_THREADS];
	t_fractal		fractals[NB_THREADS];

	if (!f)
		return (-1);
	n = -1;
	while (++n < NB_THREADS)
	{
		fractals[n] = *f;
		fractals[n].thread_id = n;
		if (pthread_create(&threads[n], NULL, fractal_thread, &fractals[n]))
			exit(exit_fractol(f, EXIT_FAILURE));
	}
	n = -1;
	while (++n < NB_THREADS)
		if (pthread_join(threads[n], NULL))
			exit(exit_fractol(f, EXIT_FAILURE));
	draw_img(f->mlx.mlx, f->mlx.win.win, f->mlx.win.img);
	show_info(f);
	return (0);
}

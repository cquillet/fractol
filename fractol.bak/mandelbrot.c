/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:54:35 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 17:17:09 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			mandel_init(t_fractal *f)
{
	f->plane = create_boxf(-2.5, 1.5, -2., 2.);
	f->z0 = create_complex(0., 0.);
	f->pause = 1;
	f->power = 2;
	clear_img(&(f->mlx.win.img));
}

static int		mandel_exit(t_cplx zn, t_cplx z)
{
	t_re			q;
	t_re			y2;

	if (cplx_mod2(zn) > 4.)
		return (1);
	q = z.re + 1.;
	y2 = z.im * z.im;
	if (((q * q) + y2) < (t_re)0.0625)
		return (-1);
	q = z.re - 0.25;
	q = q * q + y2;
	if (q * (q + (z.re - 0.25)) < (y2 / 4.))
		return (-1);
	return (0);
}

/*
** z -> z2 + c , pixel = c
*/

unsigned int	mandel_calc(t_fractal f, t_cplx z)
{
	t_cplx			zn;
	t_cplx			next;
	unsigned int	n;
	int				skip;

	zn = f.z0;
	n = 0;
	while (n < f.nb_iter_max)
	{
		if ((skip = mandel_exit(zn, z)))
			return (skip < 0 ? f.nb_iter_max : n);
		next = cplx_add(cplx_pow(zn, 2), z);
		if (!cplx_cmp(next, zn))
			return (f.nb_iter_max);
		zn = next;
		n++;
	}
	return (n);
}

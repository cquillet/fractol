/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:57:20 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 17:17:11 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			julia_init(t_fractal *f)
{
	f->plane = create_boxf(-2., 2., -2., 2.);
	f->pause = 1;
	clear_img(&(f->mlx.win.img));
}

static int		julia_exit(t_cplx zn)
{
	return (cplx_mod2(zn) > 4.);
}

/*
** z -> z ^ power + c , pixel = z0
*/

unsigned int	julia_calc(t_fractal f, t_cplx z)
{
	t_cplx			zn;
	t_cplx			next;
	unsigned int	n;

	zn = z;
	n = 0;
	while (n < f.nb_iter_max)
	{
		if (julia_exit(zn))
			return (n);
		next = cplx_add(cplx_pow(zn, f.power), f.c[JULIA]);
		if (!cplx_cmp(next, zn))
			return (f.nb_iter_max);
		zn = next;
		n++;
	}
	return (n);
}

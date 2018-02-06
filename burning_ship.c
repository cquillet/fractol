/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 01:04:43 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 16:42:09 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void			burning_init(t_fractal *f)
{
	f->plane = create_boxf(-2., 2., -2., 2.);
	f->nb_iter_max = 35;
	f->z0 = create_complex(0., 0.);
	f->pause = 1;
	f->power = 2;
	clear_img(&(f->mlx.win.img));
}

static int		burning_exit(t_cplx zn)
{
	return (cplx_mod2(zn) > 4.);
}

/*
** z -> (|Re(z)| + i|Im(z)|)2 + c , pixel = c
*/

unsigned int	burning_calc(t_fractal f, t_cplx z)
{
	t_cplx			zn;
	t_cplx			next;
	t_cplx			abs;
	unsigned int	n;

	zn = f.z0;
	n = 0;
	while (n < f.nb_iter_max)
	{
		if (burning_exit(zn))
			return (n);
		abs = create_complex(ft_absf(zn.re), ft_absf(zn.im));
		next = cplx_add(cplx_pow(abs, 2), z);
		if (!cplx_cmp(next, zn))
			return (f.nb_iter_max);
		zn = next;
		n++;
	}
	return (n);
}

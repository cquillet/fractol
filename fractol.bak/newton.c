/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:58:34 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 17:22:22 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "polynomial.h"
#include "libft.h"

void			newton_init(t_fractal *f)
{
	f->plane = create_boxf(-3., 3., -3., 3.);
	f->pause = 1;
	f->power = poly_test_deg(f->poly_newton[f->newton_type]);
	ft_strcpy(f->name[f->fractal_type], f->poly_names[f->newton_type]);
	clear_img(&(f->mlx.win.img));
}

/*
** z -> z - c * P(z) / P'(z) , pixel = z
*/

unsigned int	newton_calc(t_fractal f, t_cplx z)
{
	t_cplx			zn;
	t_cplx			next;
	t_cplx			p;
	t_cplx			d;
	unsigned int	n;

	zn = z;
	n = 0;
	while (n < f.nb_iter_max)
	{
		p = poly_calc(f.poly_newton[f.newton_type], zn);
		if (barely_zero(cplx_mod2(p)))
			return (n);
		d = poly_calc(f.poly_newton_deriv[f.newton_type], zn);
		if (barely_zero(cplx_mod2(d)))
			return (f.nb_iter_max);
		next = cplx_sub(zn, cplx_mul(f.c[NEWTON], cplx_div(p, d)));
		if (!cplx_cmp(next, zn))
			return (n);
		zn = next;
		n++;
	}
	return (n);
}

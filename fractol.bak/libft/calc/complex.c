/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:27:24 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 16:57:54 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "math.h"
#include "libft.h"

t_cplx			create_complex(t_re re, t_im im)
{
	t_cplx	z;

	z.re = re;
	z.im = im;
	return (z);
}

t_cplx			cplx_conj(t_cplx z)
{
	return (create_complex(z.re, -z.im));
}

t_re			cplx_mod(t_cplx z)
{
	return (sqrt((z.re * z.re) + (z.im * z.im)));
}

t_cplx			cplx_scalar(t_cplx z, t_re a)
{
	return (create_complex(a * z.re, a * z.im));
}

t_cplx			cplx_inv(t_cplx z)
{
	t_re	m;

	m = cplx_mod(z);
	if (barely_zero(m))
		return (create_complex(0., 0.));
	return (cplx_scalar(cplx_conj(z), 1. / (m * m)));
}

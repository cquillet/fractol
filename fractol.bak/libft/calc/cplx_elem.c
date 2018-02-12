/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:33:47 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/20 14:32:03 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "libft.h"

t_cplx			cplx_add(t_cplx x, t_cplx y)
{
	return (create_complex(x.re + y.re, x.im + y.im));
}

t_cplx			cplx_sub(t_cplx x, t_cplx y)
{
	return (create_complex(x.re - y.re, x.im - y.im));
}

t_cplx			cplx_mul(t_cplx x, t_cplx y)
{
	t_cplx		z;

	z.re = (x.re * y.re) - (x.im * y.im);
	z.im = (x.re * y.im) + (x.im * y.re);
	return (z);
}

t_cplx			cplx_pow(t_cplx x, int exp)
{
	t_cplx		half;

	if (exp < 0)
		return (cplx_pow(cplx_inv(x), -exp));
	if (exp == 0)
		return (create_complex(1., 0.));
	if (exp == 1)
		return (x);
	half = cplx_pow(x, exp / 2);
	if (exp % 2)
		return (cplx_mul(cplx_mul(half, half), x));
	return (cplx_mul(half, half));
}

t_cplx			cplx_div(t_cplx x, t_cplx y)
{
	return (cplx_mul(x, cplx_inv(y)));
}

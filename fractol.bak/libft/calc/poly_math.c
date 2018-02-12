/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:09:17 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:09:41 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.h"

t_poly				poly_derivative(t_poly p)
{
	t_poly	d;

	p.deg = poly_test_deg(p);
	if (!p.deg || !p.coeff || !p.unset)
		return (init_poly(0));
	d = init_poly(p.deg - 1);
	while (p.deg)
	{
		if (!poly_is_coeff_zero(p, p.deg))
			poly_fill_nth_deg(&d, p.deg - 1,
								cplx_scalar(p.coeff[p.deg], (t_re)(p.deg)));
		p.deg--;
		p.deg = poly_test_deg(p);
	}
	return (d);
}

t_cplx				poly_calc(t_poly p, t_cplx x)
{
	unsigned int	n;
	t_cplx			x_power_n;
	t_cplx			result;

	result = create_complex(0., 0.);
	if (!p.coeff || !p.unset)
		return (result);
	if (!poly_is_coeff_zero(p, 0))
		result = p.coeff[0];
	if (!p.deg)
		return (result);
	n = 1;
	x_power_n = x;
	while (n <= p.deg)
	{
		if (!poly_is_coeff_zero(p, n))
			result = cplx_add(result, cplx_mul(p.coeff[n], x_power_n));
		if (n++ < p.deg)
			x_power_n = cplx_mul(x_power_n, x);
	}
	return (result);
}

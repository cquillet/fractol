/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:05:30 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:45:13 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.h"
#include "libft.h"

static t_poly		poly_add_test_zero(t_poly *s, t_poly p, t_poly q,
																unsigned int d)
{
	if (!s || (poly_is_coeff_zero(p, d) && poly_is_coeff_zero(q, d)))
		return (*s);
	else if (poly_is_coeff_zero(p, d))
		poly_fill_nth_deg(s, d, q.coeff[d]);
	else if (poly_is_coeff_zero(q, d))
		poly_fill_nth_deg(s, d, p.coeff[d]);
	else
		poly_fill_nth_deg(s, d, cplx_add(p.coeff[d], q.coeff[d]));
	return (*s);
}

t_poly				poly_add(t_poly p, t_poly q)
{
	t_poly			s;
	unsigned int	d;

	d = (p.deg > q.deg ? p.deg : q.deg);
	s = init_poly(d);
	while (d)
	{
		poly_add_test_zero(&s, p, q, d);
		d--;
	}
	return (poly_add_test_zero(&s, p, q, 0));
}

t_poly				poly_scalar(t_poly p, t_re a)
{
	t_poly		q;

	if (barely_zero(a))
		return (init_poly(0));
	p.deg = poly_test_deg(p);
	q = init_poly(p.deg);
	while (p.deg)
	{
		q.coeff[p.deg] = cplx_scalar(p.coeff[p.deg], a);
		p.deg--;
		p.deg = poly_test_deg(p);
	}
	if (!poly_is_coeff_zero(p, 0))
		q.coeff[0] = cplx_scalar(p.coeff[0], a);
	return (q);
}

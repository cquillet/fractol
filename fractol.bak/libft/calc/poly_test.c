/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:07:12 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:18:37 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.h"

int					poly_is_null(t_poly p)
{
	return (p.deg == 0 && poly_is_coeff_zero(p, 0));
}

int					poly_cmp(t_poly p, t_poly q)
{
	p.deg = poly_test_deg(p);
	q.deg = poly_test_deg(q);
	while (p.deg && q.deg && p.deg == q.deg)
	{
		if (cplx_cmp(p.coeff[p.deg], q.coeff[q.deg]))
			return (1);
		p.deg = poly_test_deg(p);
		q.deg = poly_test_deg(q);
	}
	return (!p.deg && !q.deg && !cplx_cmp(p.coeff[0], q.coeff[0]));
}

unsigned int		poly_test_deg(t_poly p)
{
	if (!p.deg || !p.coeff || !p.unset)
		return (0);
	while (p.deg)
	{
		if (!poly_is_coeff_zero(p, p.deg))
			break ;
		p.deg--;
	}
	return (p.deg);
}

int					poly_is_coeff_zero(t_poly p, unsigned int n)
{
	if (n > p.deg || !p.unset || !p.coeff)
		return (1);
	if (get_bin(p.unset, n))
		return (1);
	return (!cplx_cmp(p.coeff[n], create_complex(0., 0.)));
}

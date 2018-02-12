/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_real.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:08:11 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:18:30 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.h"

t_poly				poly_deg0_real(t_re real)
{
	t_poly	p;

	p = init_poly(0);
	poly_fill_nth_deg(&p, 0, create_complex(real, 0.));
	return (p);
}

t_poly				poly_deg2_real(t_re a, t_re b, t_re c)
{
	t_poly	p;

	p = init_poly(2);
	poly_fill_nth_deg(&p, 0, create_complex(c, 0.));
	poly_fill_nth_deg(&p, 1, create_complex(b, 0.));
	poly_fill_nth_deg(&p, 2, create_complex(a, 0.));
	p.deg = poly_test_deg(p);
	return (p);
}

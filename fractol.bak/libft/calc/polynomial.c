/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:42:03 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:44:27 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.h"
#include "complex.h"
#include "libft.h"
#include <stdlib.h>

t_poly			init_poly(unsigned int deg)
{
	t_poly	p;

	p.deg = 0xffffffff;
	p.coeff = (t_cplx *)malloc((deg + 1) * sizeof(t_cplx));
	p.unset = create_tab_bin(deg + 1);
	if (!p.coeff || !p.unset)
		return (p);
	if (!deg)
	{
		let_bin(p.unset, 0, 0);
		p.coeff[0] = create_complex(0., 0.);
		p.deg = 0;
		return (p);
	}
	while (++p.deg < deg)
		let_bin(p.unset, p.deg, 1);
	let_bin(p.unset, p.deg, 0);
	p.coeff[p.deg] = create_complex(1., 0.);
	return (p);
}

/*
** return :	-1	error
**			0	P[n] = coeff (P[n] has been set fort the 1st time)
**			1	P[n] = coeff (P[n] has been changed/updated)
*/

int				poly_fill_nth_deg(t_poly *p, unsigned int n, t_cplx coeff)
{
	if (!p || n > p->deg || !(p->coeff))
		return (-1);
	if (get_bin(p->unset, n))
	{
		p->coeff[n] = coeff;
		return (let_bin(p->unset, n, 0));
	}
	p->coeff[n] = coeff;
	p->deg = poly_test_deg(*p);
	return (1);
}

void			poly_del(t_poly *p)
{
	p->deg = 0;
	ft_memdel((void **)&(p->coeff));
	ft_memdel((void **)&(p->unset));
}

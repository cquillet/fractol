/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:10:04 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:10:39 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.h"
#include "ft_printf.h"

int				poly_print(t_poly p)
{
	int				n;

	if (!(p.deg = poly_test_deg(p)))
	{
		if (p.coeff && p.unset && !get_bin(p.unset, 0))
			ft_printf("%Lf + %+Lfi\n", p.coeff[0].re, p.coeff[0].im);
		return (1);
	}
	n = 0;
	while (p.deg)
	{
		if (n > 0)
			ft_printf(" + \n");
		ft_printf("%Lf %+Lfi X", p.coeff[p.deg].re, p.coeff[p.deg].im);
		if (p.deg > 1)
			ft_printf("%u", p.deg);
		n++;
		p.deg--;
		p.deg = poly_test_deg(p);
	}
	if (!poly_is_coeff_zero(p, 0))
		ft_printf(" + \n%Lf %+Lfi", p.coeff[p.deg].re, p.coeff[p.deg].im);
	ft_printf("\n\n");
	return (n);
}

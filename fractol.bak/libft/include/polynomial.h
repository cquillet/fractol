/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:45:08 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/26 18:12:06 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYNOMIAL_H
# define POLYNOMIAL_H

# include "complex.h"
# include "tab_bin.h"

typedef struct		s_poly
{
	unsigned		deg;
	t_cplx			*coeff;
	char			*unset;
}					t_poly;

t_poly				init_poly(unsigned int deg);
t_poly				poly_deg0_real(t_re real);
t_poly				poly_deg2_real(t_re a, t_re b, t_re c);
int					poly_print(t_poly p);
void				poly_del(t_poly *p);

t_poly				poly_add(t_poly p, t_poly q);
t_poly				poly_scalar(t_poly p, t_re a);

t_cplx				poly_calc(t_poly p, t_cplx x);
t_poly				poly_derivative(t_poly p);
int					poly_fill_nth_deg(t_poly *p, unsigned int n, t_cplx coeff);

unsigned int		poly_test_deg(t_poly p);
int					poly_is_coeff_zero(t_poly p, unsigned int n);
int					poly_cmp(t_poly p, t_poly q);
int					poly_is_null(t_poly p);

#endif

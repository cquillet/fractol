/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:11:00 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:23:00 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include "float_2f.h"

# ifndef TYPEDEF_CPLX
#  define TYPEDEF_CPLX

typedef long double	t_re;
typedef long double	t_im;

# endif

typedef struct	s_cplx
{
	t_re		re;
	t_im		im;
}				t_cplx;

t_cplx			create_complex(t_re re, t_im im);
t_cplx			cplx_conj(t_cplx z);
t_re			cplx_mod(t_cplx z);
t_re			cplx_mod2(t_cplx z);
t_cplx			cplx_scalar(t_cplx z, t_re a);
t_cplx			cplx_inv(t_cplx z);

t_cplx			cplx_add(t_cplx x, t_cplx y);
t_cplx			cplx_sub(t_cplx x, t_cplx y);
t_cplx			cplx_div(t_cplx x, t_cplx y);
t_cplx			cplx_mul(t_cplx x, t_cplx y);
t_cplx			cplx_pow(t_cplx x, int exp);

int				cplx_cmp(t_cplx x, t_cplx y);
void			cplx_print(t_cplx z, int precision);
t_2f			cplx_2f(t_cplx z);

#endif

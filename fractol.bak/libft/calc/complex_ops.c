/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:33:47 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:40:00 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "libft.h"

t_re			cplx_mod2(t_cplx z)
{
	return ((z.re * z.re) + (z.im * z.im));
}

t_2f			cplx_2f(t_cplx z)
{
	return (create_2f(z.re, z.im));
}

int				cplx_cmp(t_cplx x, t_cplx y)
{
	return (!(barely_zero(x.re - y.re) && barely_zero(x.im - y.im)));
}

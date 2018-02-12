/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxf_cplx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:20:10 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/21 17:55:31 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"
#include "complex.h"

int		cplx_in_boxf(t_boxf b, t_cplx p)
{
	return (!(p.re < b.x_min || p.re > b.x_max
										|| p.im < b.y_min || p.im > b.y_max));
}

int		boxf_redim_cplx(t_boxf *b, t_cplx p)
{
	if (cplx_in_boxf(*b, p))
		return (0);
	if (p.re < b->x_min)
		b->x_min = p.re;
	else if (p.re > b->x_max)
		b->x_max = p.re;
	if (p.im < b->y_min)
		b->y_min = p.im;
	else if (p.im > b->y_max)
		b->y_max = p.im;
	return (0);
}

t_cplx	boxf_center_cplx(t_boxf b)
{
	t_cplx	p;

	p.re = (b.x_min + b.x_max) / 2.;
	p.im = (b.y_min + b.y_max) / 2.;
	return (p);
}

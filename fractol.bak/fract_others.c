/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:22:15 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 18:24:52 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include "pixel.h"
#include <time.h>
#include "libft.h"

int				recenter(t_fractal *f, t_2f zoom)
{
	t_cplx		min;
	t_cplx		max;

	min = create_complex(f->plane.x_min, f->plane.y_min);
	min = cplx_add(cplx_scalar(cplx_sub(min, f->target), zoom.x), f->target);
	max = create_complex(f->plane.x_max, f->plane.y_max);
	max = cplx_add(cplx_scalar(cplx_sub(max, f->target), zoom.y), f->target);
	if (max.re - min.re < FRACT_WIDTH_MIN || max.im - min.im > FRACT_WIDTH_MAX)
		return (0);
	f->plane = create_boxf(min.re, max.re, min.im, max.im);
	return (1);
}

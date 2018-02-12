/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 21:38:40 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 17:05:13 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"
#include "float_2f.h"

t_boxf	create_boxf(t_re x_min, t_re x_max, t_re y_min, t_re y_max)
{
	t_boxf	b;

	if (x_min > x_max)
	{
		b.x_min = x_max;
		b.x_max = x_min;
	}
	else
	{
		b.x_min = x_min;
		b.x_max = x_max;
	}
	if (y_min > y_max)
	{
		b.y_min = y_max;
		b.y_max = y_min;
	}
	else
	{
		b.y_min = y_min;
		b.y_max = y_max;
	}
	return (b);
}

int		t2f_in_boxf(t_boxf b, t_2f p)
{
	return (!(p.x < b.x_min || p.x > b.x_max
										|| p.y < b.y_min || p.y > b.y_max));
}

t_re	boxf_width(t_boxf b)
{
	return (b.x_max - b.x_min);
}

t_im	boxf_height(t_boxf b)
{
	return (b.y_max - b.y_min);
}

t_2f	boxf_center(t_boxf b)
{
	t_2f	p;

	p.x = (b.x_min + b.x_max) / 2.;
	p.y = (b.y_min + b.y_max) / 2.;
	return (p);
}

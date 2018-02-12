/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 21:38:40 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/22 18:37:12 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"
#include "pixel.h"

t_box	create_box(int x_min, int x_max, int y_min, int y_max)
{
	t_box	b;

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

int		pix_in_box(t_box b, t_pixel p)
{
	return (!(p.x < b.x_min || p.x > b.x_max
										|| p.y < b.y_min || p.y > b.y_max));
}

int		box_width(t_box b)
{
	return (b.x_max - b.x_min);
}

int		box_height(t_box b)
{
	return (b.y_max - b.y_min);
}

t_pixel	box_center(t_box b)
{
	t_pixel	p;

	p.x = (b.x_min + b.x_max) / 2;
	p.y = (b.y_min + b.y_max) / 2;
	p.color = 0;
	return (p);
}

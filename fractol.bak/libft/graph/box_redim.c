/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 21:38:40 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:02:04 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"
#include "pixel.h"

int		box_redim(t_box *b, t_pixel p)
{
	if (pix_in_box(*b, p))
		return (0);
	if (p.x < b->x_min)
		b->x_min = p.x;
	else if (p.x > b->x_max)
		b->x_max = p.x;
	if (p.y < b->y_min)
		b->y_min = p.y;
	else if (p.y > b->y_max)
		b->y_max = p.y;
	return (1);
}

int		box_big_square(t_box *b, int natural_way_x, int natural_way_y)
{
	int		w;
	int		h;

	w = box_width(*b);
	h = box_height(*b);
	if (w > h)
	{
		if (natural_way_y)
			b->y_max = b->y_min + w;
		else
			b->y_min = b->y_max - w;
		return (w);
	}
	if (natural_way_x)
		b->x_max = b->x_min + h;
	else
		b->x_min = b->x_max - h;
	return (h);
}

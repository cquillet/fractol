/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:19:47 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/22 19:17:11 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include <stdlib.h>
#include "libft.h"
#include "colors.h"
#include "pixel.h"
#include "int_2d.h"

static t_line	dda_horizontal_line(t_pixel p1, t_pixel p2)
{
	t_line	l;
	int		i;
	double	slope;

	l.len = p2.x - p1.x + 1;
	if (!(l.pixels = (t_pixel *)malloc((l.len) * sizeof(t_pixel))))
		return (l);
	slope = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	l.pixels[0] = p1;
	i = 0;
	while (++i < l.len - 1)
	{
		l.pixels[i].x = p1.x + i;
		l.pixels[i].y = (int)((double)(p1.y) + (double)i * slope);
	}
	l.pixels[l.len - 1] = p2;
	return (l);
}

static t_line	dda_vertical_line(t_pixel p1, t_pixel p2)
{
	t_line	l;
	int		i;
	double	slope;

	l.len = p2.y - p1.y + 1;
	if (!(l.pixels = (t_pixel *)malloc((l.len) * sizeof(t_pixel))))
		return (l);
	slope = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	l.pixels[0] = p1;
	i = 0;
	while (++i < l.len - 1)
	{
		l.pixels[i].y = p1.y + i;
		l.pixels[i].x = (int)((double)(p1.x) + (double)i / slope);
	}
	l.pixels[l.len - 1] = p2;
	return (l);
}

t_line			create_line(t_pixel p1, t_pixel p2)
{
	t_line	l;
	int		dx;
	int		dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	l.len = 0;
	l.pixels = NULL;
	if (dx == 0 && dy == 0)
		return (l);
	if (ft_abs(dx) < ft_abs(dy))
	{
		if (dy < 0)
			return (dda_vertical_line(p2, p1));
		return (dda_vertical_line(p1, p2));
	}
	if (dx < 0)
		return (dda_horizontal_line(p2, p1));
	return (dda_horizontal_line(p1, p2));
}

void			draw_line(t_mlx *mlx, t_pixel p1, t_pixel p2)
{
	t_line			l;

	if (!valid_pixel(p1, mlx->win.width, mlx->win.height)
		&& !valid_pixel(p2, mlx->win.width, mlx->win.height))
		return ;
	l = create_line(p1, p2);
	draw_line_direct(mlx, l);
	ft_memdel((void **)&l.pixels);
}

void			draw_line_direct(t_mlx *mlx, t_line l)
{
	unsigned int	i;
	t_pixel			p;
	unsigned int	c;

	if (!(l.pixels) || !(l.len))
		return ;
	c = l.pixels[l.len - 1].color;
	i = 0;
	while (i < (unsigned int)l.len)
	{
		p = l.pixels[i];
		p.color = rgb_between(i, create_2d(0, l.len - 1), l.pixels[0].color, c);
		put_pixel_in_img(mlx->mlx, mlx, p);
		i++;
	}
}

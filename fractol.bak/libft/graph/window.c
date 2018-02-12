/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 04:01:33 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/05 21:06:41 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "mlx.h"
#include "box.h"
#include <stdlib.h>
#include "libft.h"

t_win	create_win(t_mlx *m, char *name, int w, int h)
{
	t_win	win;

	win.name = name;
	win.width = (w < 0 || w > m->width) ? 0 : w;
	win.height = (h < 0 || h > m->height) ? 0 : h;
	win.nb_zones = 0;
	win.win = mlx_new_window(m->mlx, win.width, win.height, win.name);
	m->nb_wins++;
	return (win);
}

t_mlx	create_mlx(void *mlx, int w, int h)
{
	t_mlx	m;

	m.mlx = mlx;
	m.nb_wins = 0;
	m.width = w;
	m.height = h;
	return (m);
}

int		box_fills_in_win(t_box b, t_win win)
{
	int		w;
	int		h;

	w = b.x_max - b.x_min;
	if (w < 0)
		return (-1);
	h = b.y_max - b.y_min;
	if (h < 0)
		return (-1);
	return (w < win.width && h < win.height);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mouse_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:55:01 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 13:48:43 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_mouse_macos.h"
#include "fractol.h"
#include "pixel.h"
#include "box.h"
#include "libft.h"
#include <stdlib.h>

static void		force_zoombox_in_win(t_fractal *f)
{
	if (f->zoom.x_min < 0)
		f->zoom.x_min = 0;
	if (f->zoom.x_max >= f->mlx.win.width)
		f->zoom.x_max = f->mlx.win.width - 1;
	if (f->zoom.y_min < 0)
		f->zoom.y_min = 0;
	if (f->zoom.y_max >= f->mlx.win.height)
		f->zoom.y_max = f->mlx.win.height - 1;
}

int				fract_mouse_move(int x, int y, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	f->mouse = create_pixel(x, y, 0xFFFFFF);
	if ((f->zooming = (f->buttons & ((1 << MOUSE_LEFT) | (1 << MOUSE_RIGHT)))))
	{
		f->zoom = create_box(f->start_zoom.x, x, f->start_zoom.y, y);
		box_big_square(&f->zoom, x != f->zoom.x_min, y != f->zoom.y_min);
		f->target = pix_to_cplx(box_center(f->zoom), *f);
		force_zoombox_in_win(f);
		free(f->mlx.win.img.data);
		f->mlx.win.img.data = img_box_mask(f->mlx, f->save, f->zoom, 0x5FFFFFF);
		draw_img(f->mlx.mlx, f->mlx.win.win, f->mlx.win.img);
		return (0);
	}
	f->target = pix_to_cplx(f->mouse, *f);
	if (f->pause || !pix_in_box(f->win, f->mouse)
									|| !get_bin(f->dyn_fract, f->fractal_type))
		return (0);
	f->c[f->fractal_type] = f->target;
	clear_img(&(f->mlx.win.img));
	fractal(f);
	return (1);
}

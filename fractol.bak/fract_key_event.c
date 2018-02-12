/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_key_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:52:28 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 19:57:45 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_keys_macos.h"
#include "fractol.h"
#include <stdlib.h>

static int		key_power(int key, t_fractal *f)
{
	if (key == KEY_OPEN_BRACKET)
	{
		if (f->fractal_type == JULIA && f->power > 2)
			f->power--;
		else if (f->fractal_type == NEWTON)
			f->newton_type = (f->newton_type + NB_POLY_NEWTON - 1)
															% NB_POLY_NEWTON;
		else
			return (0);
	}
	else if (key == KEY_CLOSE_BRACKET)
	{
		if (f->fractal_type == JULIA && f->power < FRACT_POWER_MAX)
			f->power++;
		else if (f->fractal_type == NEWTON)
			f->newton_type = (f->newton_type + 1) % NB_POLY_NEWTON;
		else
			return (0);
	}
	else
		return (0);
	f->fract_init[f->fractal_type](f);
	return (1);
}

static int		key_nb_iter(int key, t_fractal *f)
{
	if (key == KEY_PAD_SUB)
	{
		f->nb_iter_max -= NB_ITER_DELTA;
		if (f->nb_iter_max < NB_ITER_MIN)
			f->nb_iter_max = NB_ITER_MIN;
	}
	else if (key == KEY_PAD_ADD)
	{
		f->nb_iter_max += NB_ITER_DELTA;
		if (f->nb_iter_max > NB_ITER_MAX)
			f->nb_iter_max = NB_ITER_MAX;
	}
	else
		return (0);
	return (1);
}

static int		key_change(int key, t_fractal *f)
{
	if (key == KEY_ENTER)
		;
	else if (key == KEY_F || key == KEY_J)
	{
		if (key == KEY_F)
			f->fractal_type = (f->fractal_type + 1) % NB_TYPE_FRACT;
		if (f->fractal_type == JULIA)
			f->c[f->fractal_type] = create_complex(0.285, 0.01);
		else if (f->fractal_type == NEWTON)
			f->c[f->fractal_type] = create_complex(1., 0.);
	}
	else
		return (0);
	f->fract_init[f->fractal_type](f);
	return (1);
}

int				fract_key_press(int key, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (key == KEY_ESCAPE)
		exit(exit_fractol(f, EXIT_SUCCESS));
	else if (f->zooming)
		return (0);
	if (key == KEY_SHIFT_LEFT || key == KEY_SHIFT_RIGHT)
		f->key_shift = 1;
	else if (key_nb_iter(key, f))
	{
		f->pause = 1;
		return (0);
	}
	else
		return (0);
	return (1);
}

int				fract_key_release(int key, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (key == KEY_SPACEBAR && get_bin(f->dyn_fract, f->fractal_type))
		f->pause = f->zooming ? 1 : !f->pause;
	else if (key == KEY_C)
		f->color_id = (f->color_id + 1) % NB_FRACT_COLORS;
	else if (key == KEY_H)
		f->display_info = (f->display_info + 1) % NB_INFO_DISPLAY;
	else if (key_change(key, f) || key_power(key, f))
		;
	else if (key_nb_iter(key, f))
		clear_img(&(f->mlx.win.img));
	else if (key == KEY_SHIFT_LEFT || key == KEY_SHIFT_RIGHT)
		f->key_shift = 0;
	else
		return (0);
	if (key != KEY_SPACEBAR && key != KEY_SHIFT_LEFT && key != KEY_SHIFT_RIGHT)
		f->pause = 1;
	fractal(f);
	return (1);
}

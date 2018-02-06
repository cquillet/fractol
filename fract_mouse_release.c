/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mouse_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:07:10 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 20:06:51 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_mouse_macos.h"
#include "fractol.h"
#include "libft.h"

static int		mouse_zoom_in(t_fractal *f)
{
	t_cplx		z1;
	t_cplx		z2;

	z1 = pix_to_cplx(create_pixel(f->zoom.x_min, f->zoom.y_min, 0), *f);
	z2 = pix_to_cplx(create_pixel(f->zoom.x_max, f->zoom.y_max, 0), *f);
	if ((z2.re - z1.re) < FRACT_WIDTH_MIN)
		return (0);
	f->target = cplx_scalar(cplx_add(z1, z2), 0.5);
	f->coeff.x = (z2.re - z1.re) / boxf_width(f->plane);
	f->coeff.y = (z2.im - z1.im) / boxf_height(f->plane);
	f->plane = create_boxf(z1.re, z2.re, z1.im, z2.im);
	f->zooming = 0;
	clear_img(&(f->mlx.win.img));
	fractal(f);
	return (1);
}

static int		mouse_zoom_out(t_fractal *f)
{
	t_cplx		z1;
	t_cplx		z2;
	t_re		w;

	z1 = pix_to_cplx(create_pixel(f->zoom.x_min, f->zoom.y_min, 0), *f);
	z2 = pix_to_cplx(create_pixel(f->zoom.x_max, f->zoom.y_max, 0), *f);
	w = boxf_width(f->plane);
	if (w * w / (z2.re - z1.re) > FRACT_WIDTH_MAX)
		return (0);
	f->target = cplx_scalar(cplx_add(z1, z2), 0.5);
	f->coeff.x = w / (z2.re - z1.re);
	f->coeff.y = boxf_height(f->plane) / (z2.im - z1.im);
	recenter(f, f->coeff);
	f->zooming = 0;
	clear_img(&(f->mlx.win.img));
	fractal(f);
	return (1);
}

static int		mouse_check_zoom(t_fractal *f, int button)
{
	t_re		side;
	size_t		n;
	t_cplx		z1;
	t_cplx		z2;
	t_re		w;

	f->zoom = create_box(
					f->start_zoom.x, f->mouse.x, f->start_zoom.y, f->mouse.y);
	side = box_big_square(
			&f->zoom, f->mouse.x != f->zoom.x_min, f->mouse.y != f->zoom.y_min);
	z1 = pix_to_cplx(create_pixel(f->zoom.x_min, f->zoom.y_min, 0), *f);
	z2 = pix_to_cplx(create_pixel(f->zoom.x_max, f->zoom.y_max, 0), *f);
	w = boxf_width(f->plane);
	f->target = pix_to_cplx(box_center(f->zoom), *f);
	if (f->save && (((side < 5 || f->buttons)
		|| (button == MOUSE_RIGHT && w * w / (z2.re - z1.re) > FRACT_WIDTH_MAX))
		|| (button == MOUSE_LEFT && (z2.re - z1.re) < FRACT_WIDTH_MIN)))
	{
		n = f->mlx.win.width * f->mlx.win.height * sizeof(unsigned int);
		ft_memcpy(f->mlx.win.img.data, f->save, n);
		draw_img(f->mlx.mlx, f->mlx.win.win, f->mlx.win.img);
		f->zooming = 0;
		return (0);
	}
	return (1);
}

static int		mouse_click(t_fractal *f, int button, int x, int y)
{
	f->mouse = create_pixel(x, y, 0xFFFFFF);
	f->pause = 1;
	if (button == MOUSE_LEFT && get_bin(f->dyn_fract, f->fractal_type))
	{
		f->c[f->fractal_type] = pix_to_cplx(f->mouse, *f);
		clear_img(&(f->mlx.win.img));
		fractal(f);
	}
	return (1);
}

int				fract_mouse_release(int button, int x, int y, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if ((f->buttons &= ~(1 << button)))
		return (0);
	if (f->key_shift && f->mouse.x == x && f->mouse.y == y && !f->zooming)
		return (mouse_click(f, button, x, y));
	f->mouse = create_pixel(x, y, 0xFFFFFF);
	if (f->zooming == (1 << button) && !mouse_check_zoom(f, button))
		return (0);
	if (f->zooming == (1 << button) && button == MOUSE_LEFT)
		mouse_zoom_in(f);
	else if (f->zooming == (1 << button) && button == MOUSE_RIGHT)
		mouse_zoom_out(f);
	else
	{
		f->zooming = 0;
		return (0);
	}
	return (1);
}

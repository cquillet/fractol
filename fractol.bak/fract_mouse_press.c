/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mouse_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:06:04 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 20:08:16 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_mouse_macos.h"
#include "fractol.h"
#include "libft.h"

static void		mouse_hit(int button, t_fractal *f)
{
	size_t		n;

	f->buttons |= (1 << button);
	f->start_zoom = f->mouse;
	n = f->mlx.win.width * f->mlx.win.height * sizeof(unsigned int);
	if (f->save)
		ft_memcpy(f->save, f->mlx.win.img.data, n);
}

int				fract_mouse_press(int button, int x, int y, void *param)
{
	t_fractal	*f;
	t_pixel		mouse;
	int			r;

	f = (t_fractal *)param;
	if (!pix_in_box(f->win, mouse = create_pixel(x, y, 0xFFFFFF)))
		return (0);
	f->mouse = mouse;
	f->pause = 1;
	if (f->zooming || f->buttons)
		return (0);
	f->target = pix_to_cplx(f->mouse, *f);
	r = 0;
	if (button == MOUSE_ROLL_FRONT || button == MOUSE_ROLL_BACK)
		r = recenter(f,
			button == MOUSE_ROLL_FRONT ? f->coeff_zoom_in : f->coeff_zoom_out);
	else if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
		mouse_hit(button, f);
	if (r)
	{
		clear_img(&(f->mlx.win.img));
		fractal(f);
	}
	return (r);
}

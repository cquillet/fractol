/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:52:42 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 17:17:16 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "int_2d.h"
#include "libft.h"
#include "mlx.h"
#include "colors.h"

static int		is_pause_symbol(t_fractal f, t_pixel p)
{
	int		w;
	t_2d	pause1_pos;
	t_2d	pause2_pos;
	t_2d	pause_dim;

	pause1_pos.y = 10;
	pause_dim.y = 30;
	if (p.y < pause1_pos.y || p.y > pause1_pos.y + pause_dim.y)
		return (0);
	w = box_width(f.win);
	pause1_pos.x = w - 30;
	pause_dim.x = 21;
	pause2_pos.x = pause1_pos.x + pause_dim.x * 2 / 3;
	if (p.x < pause1_pos.x || p.x > pause1_pos.x + pause_dim.x)
		return (0);
	pause2_pos.y = pause1_pos.y;
	if (p.x < pause1_pos.x + pause_dim.x / 3)
		return (1);
	return (p.x > pause2_pos.x);
}

static int		is_play_symbol(t_fractal f, t_pixel p)
{
	int		w;
	t_2d	play_pos;
	t_2d	play_dim;

	play_pos.y = 10;
	play_dim.y = 30;
	if (p.y < play_pos.y || p.y > play_pos.y + play_dim.y)
		return (0);
	w = box_width(f.win);
	play_pos.x = w - 25;
	play_dim.x = play_dim.y / 2;
	if (p.x < play_pos.x || p.x > play_pos.x + play_dim.x)
		return (0);
	if (p.y - play_pos.y < play_dim.y / 2)
		return (p.x - play_pos.x < p.y - play_pos.y);
	play_pos.y += play_dim.y / 2;
	return (p.x - play_pos.x + p.y - play_pos.y < play_dim.y / 2);
}

int				is_on_symbol(t_fractal f, t_pixel p)
{
	return (f.pause ? is_pause_symbol(f, p) : is_play_symbol(f, p));
}

static	void	fract_puts(t_fractal *f, int x, int y, char *s)
{
	mlx_string_put(f->mlx.mlx, f->mlx.win.win, x, y, WHITE, s);
}

void			show_info(t_fractal *f)
{
	char	*n_max;
	char	s[15][FRACT_LEN_NAME + 1];
	int		n;

	if (!f->display_info || !(n_max = ft_itoa((int)f->nb_iter_max)))
		return ;
	fract_puts(f, 10, 10, n_max);
	fract_puts(f, 10, f->mlx.win.height - 25, f->name[f->fractal_type]);
	if (f->display_info == 2 && !(n = 0))
	{
		strcpy(s[n++], "reset zoom/Julia constant: J");
		strcpy(s[n++], "reset zoom : Enter");
		strcpy(s[n++], "change Julia constant : Shift + click");
		strcpy(s[n++], "change Julia/Newton parameter : [ / ]");
		strcpy(s[n++], "play/pause (Julia) : Space");
		strcpy(s[n++], "change Color : C");
		strcpy(s[n++], "change Fractal : F");
		strcpy(s[n++], "show/Hide info : H");
		strcpy(s[n++], "nb iterations : + / -");
		while (n--)
			fract_puts(f, 10, f->mlx.win.height - 45 - 20 * n, s[n]);
	}
	ft_memdel((void **)&n_max);
}

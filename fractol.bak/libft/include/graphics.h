/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:20:30 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:26:35 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "mlx_img.h"
# include "zone.h"
# include "pixel.h"

# ifndef NB_ZONES_PER_WIN
#  define NB_ZONES_PER_WIN 1
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH (2560 / 2)
# endif

# ifndef WIN_HEIGTH
#  define WIN_HEIGTH (1440 / 2)
# endif

# ifndef CLOSE_EVENT
#  define CLOSE_EVENT 17
# endif

typedef struct	s_win
{
	char		*name;
	void		*win;
	int			width;
	int			height;
	int			nb_zones;
	t_img		img;
	t_zone		zones[NB_ZONES_PER_WIN];
}				t_win;

typedef struct	s_mlx
{
	void		*mlx;
	int			width;
	int			height;
	int			nb_wins;
	t_win		win;
}				t_mlx;

t_mlx			create_mlx(void *mlx, int w, int h);
t_win			create_win(t_mlx *m, char *name, int w, int h);
t_zone			*create_zone(t_win *win, int x0, int y0, int w, int h);

void			draw_line(t_mlx *mlx, t_pixel p1, t_pixel p2);
void			draw_line_direct(t_mlx *mlx, t_line l);

#endif

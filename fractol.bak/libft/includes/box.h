/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 21:35:05 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 19:14:38 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_H
# define BOX_H

# include "pixel.h"
# include "float_2f.h"
# include "complex.h"
# include "graphics.h"

typedef struct	s_box
{
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
}				t_box;

typedef struct	s_boxf
{
	t_re		x_min;
	t_re		x_max;
	t_re		y_min;
	t_re		y_max;
}				t_boxf;

t_box			create_box(int x_min, int x_max, int y_min, int y_max);
int				box_width(t_box b);
int				box_height(t_box b);
t_pixel			box_center(t_box b);
int				pix_in_box(t_box b, t_pixel p);
int				box_redim(t_box *b, t_pixel p);
int				box_big_square(t_box *b, int natural_way_x, int natural_way_y);

t_boxf			create_boxf(t_re x_min, t_re x_max, t_im y_min, t_im y_max);
t_re			boxf_width(t_boxf b);
t_im			boxf_height(t_boxf b);
t_2f			boxf_center(t_boxf b);

int				t2f_in_boxf(t_boxf b, t_2f p);
int				boxf_redim(t_boxf *b, t_2f p);
t_re			boxf_big_square(t_boxf *b, int natural_way_x,
															int natural_way_y);

int				cplx_in_boxf(t_boxf b, t_cplx p);
t_cplx			boxf_center_cplx(t_boxf b);
int				boxf_redim_cplx(t_boxf *b, t_cplx p);

unsigned int	*img_box_mask(t_mlx m, unsigned int *img_data, t_box mask,
															unsigned int color);

#endif

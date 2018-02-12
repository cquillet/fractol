/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:03:20 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/11 16:40:56 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_H
# define MLX_IMG_H

# include "pixel.h"

typedef struct		s_img
{
	int				width;
	int				height;
	void			*ptr;
	unsigned int	*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

int					put_pixel_in_win(void *mlx, void *win, t_pixel p);
int					put_pixel_in_img(void *mlx, void *tmlx, t_pixel p);
t_img				init_img(void *mlx, int width, int height);
int					draw_img(void *mlx, void *win, t_img img);
void				clear_img(t_img *img);

#endif

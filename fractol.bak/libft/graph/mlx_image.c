/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:53:13 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 18:51:31 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_img.h"
#include "pixel.h"
#include "graphics.h"
#include <stdlib.h>

int		put_pixel_in_win(void *mlx, void *win, t_pixel p)
{
	return (mlx_pixel_put(mlx, win, p.x, p.y, p.color));
}

int		put_pixel_in_img(void *mlx, void *tmlx, t_pixel p)
{
	t_mlx			*m;
	t_img			*i;
	unsigned int	color;

	m = (t_mlx *)tmlx;
	i = &(m->win.img);
	if (!valid_pixel(p, i->width, i->height))
		return (0);
	color = mlx_get_color_value(mlx, p.color);
	i->data[p.y * i->width + p.x] = color;
	return (1);
}

t_img	init_img(void *mlx, int width, int height)
{
	t_img	img;

	img.width = width;
	img.height = height;
	img.ptr = mlx_new_image(mlx, img.width, img.height);
	if (!img.ptr)
	{
		img.data = NULL;
		return (img);
	}
	img.data = (unsigned int *)mlx_get_data_addr(img.ptr, &img.bpp,
												&img.size_line, &img.endian);
	return (img);
}

int		draw_img(void *mlx, void *win, t_img img)
{
	return (mlx_put_image_to_window(mlx, win, img.ptr, 0, 0));
}

void	clear_img(t_img *img)
{
	int		i;

	i = 0;
	while (i < img->width * img->height)
	{
		img->data[i] = 0;
		i++;
	}
}

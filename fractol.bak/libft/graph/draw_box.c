/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:42:11 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:19:15 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"
#include "graphics.h"
#include "libft.h"
#include "mlx.h"

unsigned int	*img_box_mask(t_mlx m, unsigned int *img_data, t_box mask,
															unsigned int color)
{
	unsigned int	*new_data;
	int				x;
	int				y;
	unsigned int	c;
	size_t			n;

	n = m.win.width * m.win.height * sizeof(*img_data);
	if (!(new_data = (unsigned int*)malloc(n)))
		return (NULL);
	ft_memcpy(new_data, img_data, n);
	y = mask.y_min;
	c = mlx_get_color_value(m.mlx, color);
	while (y <= mask.y_max)
	{
		new_data[y * m.win.width + mask.x_min] = c;
		if (y == mask.y_min || y == mask.y_max)
		{
			x = mask.x_min;
			while (++x < mask.x_max)
				new_data[y * m.win.width + x] = c;
		}
		new_data[y * m.win.width + mask.x_max] = c;
		y++;
	}
	return (new_data);
}

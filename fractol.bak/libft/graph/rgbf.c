/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:54:51 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:03:48 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include "float_2f.h"
#include "scale.h"

unsigned int	spectrum_colorf(t_re value, t_re min, t_re max)
{
	int			c;

	c = (int)scalef(value, create_2f(min, max), create_2f(0., 1529.));
	if (c < 0xFF)
		return (0xFF00FE - c);
	if (c < 0x1FE)
		return (0xFF0100 + ((c - 0xFF) << 8));
	if (c < 0x2FD)
		return (0xFEFF00 - ((c - 0x1FE) << 16));
	if (c < 0x3FC)
		return (0x00FF01 + (c - 0x2FD));
	if (c < 0x4FB)
		return (0x00FEFF - ((c - 0x3FC) << 8));
	return (0x0100FF + ((c - 0x4FB) << 16));
}

unsigned int	spectrum_grayf(t_re value, t_re min, t_re max)
{
	int			c;

	c = (int)scalef(value, create_2f(min, max), create_2f(0., 255.));
	return ((c << 16) | (c << 8) | c);
}

unsigned int	rgb_darkerf(unsigned int color, t_re value, t_re start,
																	t_re black)
{
	return (rgb_betweenf(value, create_2f(start, black), color, 0x000000));
}

unsigned int	rgb_lighterf(unsigned int color, t_re value, t_re start,
																	t_re white)
{
	return (rgb_betweenf(value, create_2f(start, white), color, 0xFFFFFF));
}

unsigned int	rgb_betweenf(t_re value, t_2f start_end,
							unsigned int color_start, unsigned int color_end)
{
	unsigned int	c;
	t_re			start;
	t_re			end;

	start = start_end.x;
	end = start_end.y;
	c = ((unsigned int)scalef(value, start_end,
		create_2f((color_start >> 16) & 0xFF, ((color_end >> 16) & 0xFF)))
		<< 16);
	c |= ((unsigned int)scalef(value, start_end,
		create_2f((color_start >> 8) & 0xFF, ((color_end >> 8) & 0xFF)))
		<< 8);
	c |= ((unsigned int)scalef(value, start_end,
		create_2f(color_start & 0xFF, color_end & 0xFF)));
	return (c);
}

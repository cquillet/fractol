/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:54:51 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/24 22:30:12 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include "int_2d.h"
#include "scale.h"

unsigned int	spectrum_color(int value, int min, int max)
{
	int		c;

	c = scale(value, create_2d(min, max), create_2d(0, 0x5F9));
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

unsigned int	spectrum_gray(int value, int min, int max)
{
	int		c;

	c = scale(value, create_2d(min, max), create_2d(0, 0xFF));
	return ((c << 16) | (c << 8) | c);
}

unsigned int	rgb_darker(unsigned int color, int value, int start, int black)
{
	return (rgb_between(value, create_2d(start, black), color, 0x000000));
}

unsigned int	rgb_lighter(unsigned int color, int value, int start, int white)
{
	return (rgb_between(value, create_2d(start, white), color, 0xFFFFFF));
}

unsigned int	rgb_between(int value, t_2d start_end,
							unsigned int color_start, unsigned int color_end)
{
	unsigned int	c;
	int				start;
	int				end;

	start = start_end.x;
	end = start_end.y;
	c = (scale(value, start_end,
		create_2d((color_start >> 16) & 0xFF, ((color_end >> 16) & 0xFF)))
		<< 16);
	c |= (scale(value, start_end,
		create_2d((color_start >> 8) & 0xFF, ((color_end >> 8) & 0xFF)))
		<< 8);
	c |= (scale(value, start_end,
		create_2d(color_start & 0xFF, color_end & 0xFF)));
	return (c);
}

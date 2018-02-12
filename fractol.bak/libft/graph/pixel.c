/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 16:08:37 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/03 17:41:55 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"
#include "libft.h"

t_pixel	create_pixel(int x, int y, unsigned int color)
{
	t_pixel	p;

	p.x = x;
	p.y = y;
	p.color = color;
	return (p);
}

int		valid_pixel(t_pixel p, int width, int height)
{
	return (p.x >= 0 && p.y >= 0 && p.x < width && p.y < height);
}

void	print_pixel_info(t_pixel p)
{
	ft_putstr("PIXEL ");
	ft_putnbr_base((unsigned int)(&p), 16);
	ft_putstr("\n{\n\tx = ");
	ft_putnbr(p.x);
	ft_putstr("\n\ty = ");
	ft_putnbr(p.y);
	ft_putstr("\n\tcolor = ");
	ft_putnbr_base(p.color, 16);
	ft_putstr("\n}\n");
}

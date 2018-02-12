/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:18:41 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:26:45 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

typedef struct		s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
}					t_pixel;

typedef struct		s_line
{
	t_pixel			*pixels;
	int				len;
}					t_line;

t_pixel				create_pixel(int x, int y, unsigned int color);
t_line				create_line(t_pixel p1, t_pixel p2);
void				print_pixel_info(t_pixel p);
int					valid_pixel(t_pixel p, int width, int height);

#endif

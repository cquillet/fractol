/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:20:12 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/10 15:21:07 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZONE_H
# define ZONE_H

# include "mlx_img.h"

typedef struct	s_zone
{
	int			x0;
	int			y0;
	int			width;
	int			height;
	int			framed;
	int			priority;
	t_img		mask;
}				t_zone;

void			init_zone(t_zone *z, int x0, int y0, int w, int h);

#endif

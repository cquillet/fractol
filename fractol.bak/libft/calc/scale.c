/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 12:23:21 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 17:00:11 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scale.h"
#include "int_2d.h"
#include "float_2f.h"
#include "libft.h"

int		scale(int value, t_2d min_max, t_2d new_min_max)
{
	int		min;
	int		max;
	int		new_min;
	int		new_max;

	max = min_max.y;
	new_max = new_min_max.y;
	if (value == max)
		return (new_max);
	min = min_max.x;
	new_min = new_min_max.x;
	if (value == min)
		return (new_min);
	if (!(max - min))
		return (0);
	return ((value - min) * (new_max - new_min) / (max - min) + new_min);
}

t_re	scalef(t_re value, t_2f min_max, t_2f new_min_max)
{
	t_re	min;
	t_re	max;
	t_re	new_min;
	t_re	new_max;

	max = min_max.y;
	new_max = new_min_max.y;
	if (barely_equals(value, max))
		return (new_max);
	min = min_max.x;
	new_min = new_min_max.x;
	if (barely_equals(value, min))
		return (new_min);
	if (barely_zero(max - min))
		return (0.);
	return ((value - min) / (max - min) * (new_max - new_min) + new_min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 20:03:21 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 17:17:06 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_add(t_vector u, t_vector v)
{
	t_vector	add;

	add.x = u.x + v.x;
	add.y = u.y + v.y;
	add.z = u.z + v.z;
	return (add);
}

t_vector	vector_cross(t_vector u, t_vector v)
{
	t_vector	cross;

	cross.x = u.y * v.z - u.z * v.y;
	cross.y = u.z * v.x - u.x * v.z;
	cross.z = u.x * v.y - u.y * v.x;
	return (cross);
}

t_re		vector_dot(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

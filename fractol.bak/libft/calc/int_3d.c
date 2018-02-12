/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 21:25:53 by cquillet          #+#    #+#             */
/*   Updated: 2017/07/12 21:29:28 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_3d.h"
#include "vector.h"

t_3d	vector_to_int(t_vector v)
{
	t_3d	p;

	p.x = (int)v.x;
	p.y = (int)v.y;
	p.z = (int)v.z;
	return (p);
}

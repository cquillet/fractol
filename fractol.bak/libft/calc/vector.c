/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:36:57 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 17:10:27 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

t_vector	create_vector(t_re x, t_re y, t_re z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_re		vector_mod(t_vector v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vector	vector_scalar(t_vector v, t_re a)
{
	t_vector	w;

	w.x = a * v.x;
	w.y = a * v.y;
	w.z = a * v.z;
	return (w);
}

t_vector	vector_unit(t_vector v)
{
	t_re	modulus;

	modulus = vector_mod(v);
	if (barely_equals(modulus, 1.0) || barely_zero(modulus))
		return (v);
	return (vector_scalar(v, 1.0 / modulus));
}

t_vector	vector_map(t_vector v, t_re (*f)(t_re))
{
	t_vector	u;

	u.x = (*f)(v.x);
	u.y = (*f)(v.y);
	u.z = (*f)(v.z);
	return (u);
}

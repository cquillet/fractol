/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:55:53 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:27:06 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# ifndef TYPEDEF_CPLX
#  define TYPEDEF_CPLX

typedef long double	t_re;
typedef long double	t_im;

# endif

typedef struct	s_vector
{
	t_re		x;
	t_re		y;
	t_re		z;
}				t_vector;

t_vector		create_vector(t_re x, t_re y, t_re z);
t_re			vector_mod(t_vector v);
t_vector		vector_map(t_vector v, t_re (*f)(t_re));
t_vector		vector_scalar(t_vector v, t_re a);
t_vector		vector_unit(t_vector v);

t_vector		vector_add(t_vector u, t_vector v);
t_vector		vector_cross(t_vector u, t_vector v);
t_re			vector_dot(t_vector u, t_vector v);

#endif

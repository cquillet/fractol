/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_2f.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 20:12:49 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/29 20:21:55 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_2F_H
# define FLOAT_2F_H

# ifndef TYPEDEF_CPLX
#  define TYPEDEF_CPLX

typedef long double	t_re;
typedef long double	t_im;

# endif

typedef struct		s_2f
{
	t_re			x;
	t_re			y;
}					t_2f;

t_2f				create_2f(t_re x, t_re y);

#endif

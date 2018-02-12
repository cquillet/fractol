/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:12:10 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/05 22:58:23 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLAR_H
# define POLAR_H

typedef struct	s_polar
{
	double		mod;
	double		rad;
	double		deg;
}				t_polar;

t_polar			create_polar(double mod, double angle, int angular_type);

#endif

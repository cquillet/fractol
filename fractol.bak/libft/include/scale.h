/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:45:48 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 17:02:16 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALE_H
# define SCALE_H

# include "int_2d.h"
# include "float_2f.h"

int		scale(int value, t_2d min_max, t_2d new_min_max);
t_re	scalef(t_re value, t_2f min_max, t_2f new_min_max);

#endif

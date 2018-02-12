/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:38:36 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/05 22:53:42 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>

typedef struct	s_matrix
{
	int			width;
	int			height;
	double		**data;
}				t_matrix;

t_matrix		*new_matrix(int width, int height);
double			scalar(t_matrix a, int row, t_matrix b, int column);
t_matrix		*add_matrix(t_matrix a, t_matrix b);
t_matrix		*mul_matrix(t_matrix a, t_matrix b);

#endif

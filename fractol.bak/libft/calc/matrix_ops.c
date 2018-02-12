/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:41:08 by cquillet          #+#    #+#             */
/*   Updated: 2017/03/08 00:16:35 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double		scalar(t_matrix a, int row, t_matrix b, int column)
{
	int		i;
	int		scalar;

	if (a.width != b.height)
		return (0.0);
	scalar = (0.0);
	i = -1;
	while (++i < a.width)
		scalar += a.data[i][row] * b.data[column][i];
	return (scalar);
}

t_matrix	*add_matrix(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	t_matrix	*sum;

	if (a.width - b.width || a.height - b.height)
		return (NULL);
	sum = new_matrix(a.width, a.height);
	i = 0;
	while (i < sum->width)
	{
		j = 0;
		while (j < sum->height)
		{
			sum->data[i][j] = a.data[i][j] + b.data[i][j];
			j++;
		}
		i++;
	}
	return (sum);
}

t_matrix	*mul_matrix(t_matrix a, t_matrix b)
{
	int			r;
	int			c;
	t_matrix	*mul;

	if (a.width - b.height || a.height - b.width)
		return (NULL);
	mul = new_matrix(a.width, a.height);
	r = -1;
	while (++r < mul->height)
	{
		c = -1;
		while (++c < mul->width)
			mul->data[c][r] = scalar(a, r, b, c);
	}
	return (mul);
}

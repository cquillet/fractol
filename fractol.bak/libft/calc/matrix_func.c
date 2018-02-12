/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:10:25 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/05 22:41:21 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdlib.h>

t_matrix	*new_matrix(int width, int height)
{
	t_matrix	*m;
	int			i;

	if (!(m = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	m->width = width;
	m->height = height;
	if (!(m->data = (double **)malloc(width * sizeof(double *))))
	{
		free(m);
		return (NULL);
	}
	i = 0;
	while (i < width)
	{
		if (!(m->data[i] = (double *)malloc(height * sizeof(double))))
		{
			while (i--)
				free(m->data[i]);
			return (NULL);
		}
		i++;
	}
	return (m);
}

t_matrix	*new_matrix_col(int height, int *vector)
{
	t_matrix	*m;
	int			i;

	if (!(m = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	m->width = 1;
	m->height = height;
	if (!(m->data = (double **)malloc(sizeof(double *))))
	{
		free(m);
		return (NULL);
	}
	if (!(m->data[0] = (double *)malloc(height * sizeof(double))))
	{
		free(m->data[0]);
		return (NULL);
	}
	if (vector == NULL)
		return (m);
	i = -1;
	while (++i < height)
		m->data[0][i] = (double)vector[i];
	return (m);
}

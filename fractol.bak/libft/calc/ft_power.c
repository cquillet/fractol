/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:36:31 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/15 15:54:26 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_power(int a, int exp)
{
	int		half;

	if (exp == 0)
		return (1);
	if (exp == 1)
		return (a);
	if (a == 0 || exp < 0)
		return (0);
	half = ft_power(a, exp / 2);
	if (exp % 2)
		return (a * half * half);
	return (half * half);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:26:20 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/06 21:07:09 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *s)
{
	int		c;
	int		base;
	int		sign;

	while (*s == ' ')
		s++;
	if (*s == '-' || *s == '+')
		sign = (*s++ == '-');
	base = 2;
	while (*s)
	{
		c = ft_ishex(*s++);
		if (c < 0)
			return (0);
		if (c + 1 > base)
			base = c + 1;
	}
	if (sign)
		return ((base != 10) ? 0 : 10);
	return (base);
}

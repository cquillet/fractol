/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:33:24 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/17 16:34:40 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *s, unsigned int base)
{
	unsigned char	j;
	long			r;
	int				sign;

	while (*s == ' ' || *s == '\t' || *s == '\n'
			|| *s == '\r' || *s == '\v' || *s == '\f')
		s++;
	if ((sign = (*s == '-')) && (base != 10))
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	r = 0;
	while (*s)
	{
		j = (unsigned char)*s++;
		if ('A' <= j && j <= 'Z')
			j += ('a' - 'A');
		j = ('0' <= j && j <= '9') ? j - '0' : j - 'a' + 10;
		if (j >= base)
			return ((int)(sign ? -r : r));
		r = base * r + j;
	}
	return ((int)(sign ? -r : r));
}

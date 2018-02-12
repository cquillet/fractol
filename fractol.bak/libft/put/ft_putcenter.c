/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcenter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 23:16:32 by cquillet          #+#    #+#             */
/*   Updated: 2017/02/14 01:09:21 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcenter(const char *s, int width, int c)
{
	int		len;
	int		side;
	int		i;

	len = ft_strlen(s);
	if (len >= width)
		return (ft_putstr(s));
	side = (width - len) / 2;
	i = 0;
	while (i++ < side)
		ft_putchar(c);
	ft_putstr(s);
	i += len;
	while (i++ < width)
		ft_putchar(c);
}

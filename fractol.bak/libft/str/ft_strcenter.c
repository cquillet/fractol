/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcenter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:05:30 by cquillet          #+#    #+#             */
/*   Updated: 2017/02/14 02:01:40 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcenter(char *s, size_t width, int c)
{
	char	*dst;
	char	*save;
	size_t	len;
	size_t	side;
	size_t	nb_bytes;

	if (!s || ((len = ft_strlen(s)) >= width))
		return (s);
	side = (width - len) / 2;
	nb_bytes = len + (width - len) * ft_lenchar(c);
	if (!(dst = (char *)malloc(nb_bytes + 1)) || nb_bytes == len)
		return (NULL);
	save = dst;
	dst += ft_strset(dst, c, side);
	ft_strncpy(dst, s, len);
	dst += len;
	ft_strset(dst, c, width - len - side);
	return (save);
}

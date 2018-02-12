/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 23:27:28 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/05 22:33:33 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	rec_unicode(char *s, int c, int n, int mask)
{
	if (n < 1)
		return ;
	if (n == 1)
	{
		s[n - 1] = (mask | c);
		return ;
	}
	rec_unicode(s, c >> 6, n - 1, (mask >> 1) | 0x80);
	s[n - 1] = ((0x3f & c) | 0x80);
}

size_t			ft_strset(char *dst, int c, size_t n)
{
	size_t	len;

	if (!dst || !(len = ft_lenchar(c)) || !n)
		return (0);
	dst[n * len] = '\0';
	if (len == 1)
		dst[0] = c;
	else
		rec_unicode(dst, c, len, 0x80);
	while (n--)
	{
		ft_memcpy(dst + len, dst, len);
		dst += len;
	}
	return (n * len);
}

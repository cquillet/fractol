/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:34:21 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/05 22:35:02 by cquillet         ###   ########.fr       */
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

char			*ft_strmset(int c, size_t n)
{
	size_t	len;
	char	*dst;
	char	*save;

	len = ft_lenchar(c);
	if (!(dst = (char *)malloc(n * len + 1)))
		return (NULL);
	save = dst;
	dst[n * len] = '\0';
	if (n == 0 || len == 0)
		return (dst);
	if (len == 1)
		dst[0] = c;
	else
		rec_unicode(dst, c, len, 0x80);
	while (n--)
	{
		ft_memcpy(dst + len, dst, len);
		dst += len;
	}
	return (save);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:00:04 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/15 23:49:42 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len;
	const char	*s;
	char		*d;

	len = 0;
	d = dst;
	while (*d != '\0' && len < size)
	{
		len++;
		d++;
	}
	s = src;
	if (size == len)
		return (size + ft_strlen(s));
	i = 0;
	while (*s != '\0')
	{
		if (i++ < size - len - 1)
			*d++ = *s;
		s++;
	}
	*d = '\0';
	return (len + s - src);
}

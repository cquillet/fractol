/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:45:23 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/10 04:30:06 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*s_dst;
	unsigned char	*s_src;

	ch = (unsigned char)c;
	s_dst = (unsigned char *)dst;
	s_src = (unsigned char *)src;
	while (n > 0)
	{
		*s_dst = *s_src;
		s_dst++;
		if (*s_src == ch)
			return (s_dst);
		s_src++;
		n--;
	}
	return (NULL);
}

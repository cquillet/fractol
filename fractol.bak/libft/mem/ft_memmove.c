/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:55:07 by cquillet          #+#    #+#             */
/*   Updated: 2016/12/23 15:35:50 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s_dst;
	char	*s_src;
	size_t	i;

	s_dst = (char *)dst;
	s_src = (char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			s_dst[i] = s_src[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len--)
			s_dst[len] = s_src[len];
	}
	return (dst);
}

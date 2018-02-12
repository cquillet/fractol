/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:39:04 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/10 04:16:51 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s_dst;
	char	*s_src;

	s_dst = (char *)dst;
	s_src = (char *)src;
	while (n > 0)
	{
		*s_dst = *s_src;
		s_dst++;
		s_src++;
		n--;
	}
	return (dst);
}

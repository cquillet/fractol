/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:20:36 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/09 10:47:39 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	n;

	n = 0;
	while (*src && n < len)
	{
		dst[n] = *src++;
		n++;
	}
	while (n < len)
	{
		dst[n] = '\0';
		n++;
	}
	return (dst);
}

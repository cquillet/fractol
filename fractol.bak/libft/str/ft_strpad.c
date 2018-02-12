/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:05:55 by cquillet          #+#    #+#             */
/*   Updated: 2017/03/07 19:23:49 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strpad(char *s, int width, int c)
{
	char	*dst;
	size_t	len;
	size_t	nb_bytes;

	if (!s || width == -INT_MIN)
		return (NULL);
	nb_bytes = (width < 0) ? (size_t)(-width) : (size_t)width;
	if ((len = ft_strlen(s)) >= nb_bytes)
		return (s);
	if (!(dst = (char *)malloc(nb_bytes + 1)))
		return (NULL);
	if (width < 0)
	{
		ft_strset(dst, c, nb_bytes - len);
		ft_strcpy(dst + nb_bytes - len, s);
	}
	else
	{
		ft_strcpy(dst, s);
		ft_strset(dst + len, c, nb_bytes - len);
	}
	return (dst);
}

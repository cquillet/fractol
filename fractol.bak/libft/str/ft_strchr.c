/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:21:30 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/03 16:12:52 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	chr;
	char	*r;

	chr = (char)c;
	r = (char *)s;
	i = 0;
	while (r[i])
	{
		if (r[i] == chr)
			return (r + i);
		i++;
	}
	if (!chr)
		return (r + i);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:30:52 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/08 23:59:03 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	p;
	char	chr;
	char	*r;
	char	found;

	chr = (char)c;
	r = (char *)s;
	found = 0;
	i = 0;
	while (r[i])
	{
		while (r[i] && r[i] != chr)
			i++;
		if (r[i] == chr)
		{
			p = i;
			found = 1;
		}
		if (r[i])
			i++;
	}
	if (found)
		return (r + p);
	return (NULL);
}

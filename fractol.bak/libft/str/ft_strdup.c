/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:11:10 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:26:28 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	n;

	n = 0;
	while (src[n])
		n++;
	if (!(dest = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	n = 0;
	while (*src)
	{
		dest[n] = *src++;
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

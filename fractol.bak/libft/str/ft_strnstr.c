/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:57:13 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/10 04:14:54 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	char	*b;

	b = (char *)big;
	if (*little == '\0')
		return (b);
	i = 0;
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i] && big[i] != little[j] && i < n)
			i++;
		while (big[i + j] && little[j] && big[i + j] == little[j] && i + j < n)
			j++;
		if (little[j] == '\0')
			return (&b[i]);
		if (big[i + j] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}

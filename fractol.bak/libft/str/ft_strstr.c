/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:44:43 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/10 04:08:23 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	char	*b;

	b = (char *)big;
	if (*little == '\0')
		return (b);
	i = 0;
	while (big[i])
	{
		j = 0;
		while (big[i] && big[i] != little[j])
			i++;
		while (big[i + j] && little[j] && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return (&b[i]);
		if (big[i + j] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}

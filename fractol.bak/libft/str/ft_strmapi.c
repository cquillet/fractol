/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:45:31 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:27:19 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*alloc;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(alloc = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		alloc[i] = (*f)(i, s[i]);
		i++;
	}
	alloc[i] = '\0';
	return (alloc);
}

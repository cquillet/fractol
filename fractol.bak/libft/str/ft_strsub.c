/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:47:06 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:29:58 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*alloc;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	if (!(alloc = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i] && i < start)
		i++;
	j = 0;
	while (s[i + j] && j < len)
	{
		alloc[j] = s[i + j];
		j++;
	}
	alloc[j] = '\0';
	return (alloc);
}

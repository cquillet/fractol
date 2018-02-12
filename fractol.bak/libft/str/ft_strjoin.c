/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:56:49 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:26:44 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*alloc;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (!(alloc = (char *)malloc((i + j + 1) * sizeof(char))))
		return (NULL);
	alloc[i + j] = '\0';
	i = 0;
	while (s1[i++])
		alloc[i - 1] = s1[i - 1];
	i--;
	j = 0;
	while (s2[j++])
		alloc[i + j - 1] = s2[j - 1];
	return (alloc);
}

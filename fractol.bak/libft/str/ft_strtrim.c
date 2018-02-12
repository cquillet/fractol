/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:09:07 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:35:33 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*alloc;
	long	i;
	long	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	j = i;
	while (s[j])
		j++;
	while (j > i && (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n'))
		j--;
	if (!(alloc = (char *)malloc((j - i + 1) * sizeof(char))))
		return (NULL);
	alloc[j - i] = '\0';
	while (j--)
		alloc[j - i] = s[j];
	return (alloc);
}

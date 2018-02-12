/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 04:15:36 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/05 22:49:41 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memlen(void *tab, size_t content_size)
{
	int		len;
	size_t	i;
	char	is_null;
	char	*byte;

	len = 0;
	while (tab)
	{
		i = 0;
		is_null = 1;
		byte = (char *)tab;
		while (i < content_size)
			if (!(is_null = (byte[i++] == 0)))
				break ;
		if (is_null)
			break ;
		tab += content_size;
		len++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:48:49 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/06 20:40:21 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	ch;

	s = (unsigned char *)b;
	ch = (unsigned char)c;
	while (len > 0)
	{
		*s = ch;
		s++;
		len--;
	}
	return (b);
}

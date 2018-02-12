/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:14:12 by cquillet          #+#    #+#             */
/*   Updated: 2017/02/14 03:27:40 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int		ft_lenchar(int c)
{
	int		len;

	if (MB_CUR_MAX == 1)
		return (c < 0x100);
	if (c < 0x80)
		return (1);
	len = 1;
	while (c >= (0x40 << (5 * len++)))
		;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:20:27 by cquillet          #+#    #+#             */
/*   Updated: 2017/07/18 16:41:43 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishex(int c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	if ('A' <= c && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}
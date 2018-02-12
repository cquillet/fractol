/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 11:51:29 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/17 15:58:26 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_bin.h"
#include <stdlib.h>

char			*create_tab_bin(unsigned int n)
{
	if (!n)
		return (NULL);
	if (n % 8)
		return ((char *)malloc((n / 8) + 1));
	return ((char *)malloc(n / 8));
}

char			get_bin(char *t, unsigned int i)
{
	if (!t)
		return (0);
	return ((t[i / 8] >> (i % 8)) & 0x01);
}

int				let_bin(char *t, unsigned int i, char value)
{
	if (!t)
		return (-1);
	if (value)
		t[i / 8] |= (1 << (i % 8));
	else
		t[i / 8] &= (~(1 << (i % 8)));
	return (value != 0);
}

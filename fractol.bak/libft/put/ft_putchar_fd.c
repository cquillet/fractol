/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:31:22 by cquillet          #+#    #+#             */
/*   Updated: 2017/02/14 01:20:26 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	rec_putchar_fd(int c, int fd, int n, int mask)
{
	char	ch;

	if (n < 1)
		return ;
	if (n == 1)
	{
		ch = (mask | c);
		write(fd, &ch, 1);
		return ;
	}
	rec_putchar_fd(c >> 6, fd, n - 1, (mask >> 1) | 0x80);
	ch = ((0x3f & c) | 0x80);
	write(fd, &ch, 1);
}

void			ft_putchar_fd(int c, int fd)
{
	if (MB_CUR_MAX == 1)
	{
		if (c < 0x100)
			write(fd, (char *)&c, 1);
		return ;
	}
	if (c < 0x80)
	{
		write(fd, &c, 1);
		return ;
	}
	rec_putchar_fd(c, fd, ft_lenchar(c), 0x80);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:42:55 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/11 21:27:50 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	n;
	char	*t;

	n = ft_strlen(s);
	t = ft_strdup(s);
	t[n] = '\n';
	write(fd, t, n + 1);
	ft_memdel((void **)&t);
}

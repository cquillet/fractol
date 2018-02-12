/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 16:35:33 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/05 22:35:20 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, unsigned int base, int fd)
{
	char	*s;

	if ((s = ft_itoa_base(n, base)))
	{
		ft_putstr_fd(s, fd);
		free(s);
	}
}

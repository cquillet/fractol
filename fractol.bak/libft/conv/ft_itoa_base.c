/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:34:26 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:21:23 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, unsigned int base)
{
	char			b[17];
	char			*r;
	int				len;
	unsigned int	l;

	ft_strcpy(b, "0123456789abcdef");
	if (base == 10)
		return (ft_itoa(n));
	l = (unsigned int)(n);
	len = 0;
	while (++len && l >= base)
		l /= base;
	if (!(r = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	r[len] = '\0';
	l = (unsigned int)(n);
	while (l >= base && len--)
	{
		r[len] = b[l % base];
		l /= base;
	}
	r[0] = b[l];
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:10:59 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:21:40 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	long	i;
	int		len;
	int		sign;

	len = 1;
	i = (n < 0) ? -(long)n : (long)n;
	while (++len && i > 9)
		i /= 10;
	sign = (n < 0);
	if (!(s = (char *)malloc((len + sign) * sizeof(char))))
		return (NULL);
	if (sign)
		s[0] = '-';
	s[len + sign - 1] = '\0';
	i = (n < 0) ? -(long)n : (long)n;
	while (--len > 0)
	{
		s[len + sign - 1] = (i % 10) + '0';
		i /= 10;
	}
	return (s);
}

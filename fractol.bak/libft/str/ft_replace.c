/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 06:18:21 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:53:37 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip(const char *s, const char *old, int len)
{
	if (*old == '\0')
		return (len);
	if (*s == '\0')
		return (0);
	if (*s == *old)
		return (skip(s + 1, old + 1, len + 1));
	return (1);
}

static size_t	final_len(const char *s, const char *old, size_t l_new)
{
	size_t		len;
	size_t		l_old;
	size_t		next;

	len = ft_strlen(s);
	if (*old == '\0')
		return (len + l_new);
	if (*s == '\0')
		return (0);
	l_old = ft_strlen(old);
	while (*s != '\0')
	{
		next = skip(s, old, 1);
		if (next == 0)
			return (len);
		if (next > 1)
		{
			next--;
			len = (len - l_old) + l_new;
		}
		s += next;
	}
	return (len);
}

char			*ft_replace(const char *s, const char *old, const char *new)
{
	size_t		l_new;
	char		*cpy;
	size_t		next;

	if (!old || !s || !new)
		return (ft_strjoin(s, new));
	l_new = ft_strlen(new);
	if (!(cpy = (char *)malloc((final_len(s, old, l_new) + 1) * sizeof(char))))
		return (NULL);
	cpy[0] = '\0';
	while (*s != '\0')
	{
		next = skip(s, old, 1);
		if (next == 0)
			return (ft_strcat(cpy, s));
		if (next > 1)
		{
			ft_strcat(cpy, new);
			next--;
		}
		else
			ft_strncat(cpy, s, 1);
		s += next;
	}
	return (cpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:55:48 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:25:37 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*l;
	unsigned char	*src;
	unsigned char	*dst;
	size_t			i;

	if (!(l = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	l->next = NULL;
	l->content = NULL;
	l->content_size = (content == 0) ? 0 : content_size;
	if (content == 0)
		return (l);
	if (!(dst = (unsigned char *)malloc(content_size)))
		return (NULL);
	src = (unsigned char *)content;
	i = 0;
	while (i < content_size)
		dst[i++] = *src++;
	l->content = (void *)dst;
	return (l);
}

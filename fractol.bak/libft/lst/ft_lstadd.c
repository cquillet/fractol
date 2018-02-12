/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:14:41 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/15 20:14:58 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list		*l;

	if (new == NULL)
	{
		new = *alst;
		return ;
	}
	l = new;
	while (l->next != NULL)
		l = l->next;
	l->next = *alst;
	*alst = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:51:19 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/15 17:19:43 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (*alst == NULL)
		return ;
	while (*alst != NULL)
	{
		tmp = (**alst).next;
		ft_lstdelone(alst, del);
		*alst = tmp;
	}
}

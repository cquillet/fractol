/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:19:46 by cquillet          #+#    #+#             */
/*   Updated: 2016/12/12 16:36:44 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*cpy;

	if (lst == NULL)
		return (NULL);
	cpy = (*f)(lst);
	if (cpy == NULL)
		return (NULL);
	cpy->next = ft_lstmap(lst->next, f);
	return (cpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:15:15 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/24 15:24:32 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*c(t_list *d, t_list *y, t_list *l, t_list *(*f)(t_list *e))
{
	t_list *mod;

	mod = f(l);
	while (l)
	{
		if (l->next != NULL)
		{
			mod->next = f(l->next);
			y->next = ft_lstnew(mod->next->content, mod->next->content_size);
			if (y->next == NULL)
				return (NULL);
		}
		mod = mod->next;
		y = y->next;
		l = l->next;
	}
	return (d);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy;
	t_list	*mod;
	t_list	*deb;

	if (lst == NULL || f == NULL)
		return (NULL);
	mod = f(lst);
	if (!(cpy = ft_lstnew(mod->content, mod->content_size)))
		return (NULL);
	mod->next = f(lst->next);
	if (!(cpy->next = ft_lstnew(mod->next->content, mod->next->content_size)))
		return (NULL);
	deb = cpy;
	lst = lst->next;
	cpy = cpy->next;
	return (c(deb, cpy, lst, f));
}

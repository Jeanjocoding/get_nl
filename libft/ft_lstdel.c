/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:08:20 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/25 18:49:19 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *deb;

	while (*alst)
	{
		deb = (*alst)->next;
		ft_lstdelone(alst, del);
		(*alst) = deb;
	}
	alst = NULL;
}

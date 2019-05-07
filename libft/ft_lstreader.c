/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:21:08 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/24 15:22:31 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreader(t_list **lst)
{
	t_list	*deb;

	deb = *lst;
	while (*lst)
	{
		ft_putendl((*lst)->content);
		(*lst) = (*lst)->next;
	}
	return (deb);
}

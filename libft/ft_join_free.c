/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:47:04 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/15 11:32:56 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_free(char *s1, char *s2)
{
	char	*join;

	join = NULL;
	if (!(join = ft_strjoin(s1, s2)))
		return (NULL);
	ft_memdel((void**)&s1);
	ft_memdel((void**)&s2);
	return (join);
}

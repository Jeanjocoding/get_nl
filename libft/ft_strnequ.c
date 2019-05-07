/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:11:03 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/25 20:21:21 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (1);
	if (s1 == NULL && s2 == NULL)
		return (1);
	if ((s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL))
		return (0);
	while (i < n)
	{
		if ((s2[i] == '\0') && (s1[i] == '\0'))
			return (1);
		if ((s2[i] == '\0') && (s1[i] != '\0'))
			return (0);
		if ((s2[i] != '\0') && (s1[i] == '\0'))
			return (0);
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

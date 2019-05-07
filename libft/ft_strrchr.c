/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:46:53 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/24 16:52:10 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c2;
	int				i;

	i = ft_strlen(s);
	c2 = c;
	if (s == NULL)
		return (NULL);
	while (i > 0)
	{
		if (s[i] == c2)
			return ((char*)&s[i]);
		i--;
	}
	if (s[i] == c2)
		return ((char*)&s[i]);
	return (NULL);
}

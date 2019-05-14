/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:09:09 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/14 14:31:17 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c2;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	c2 = c;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c2)
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}

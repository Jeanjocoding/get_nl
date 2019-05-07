/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:24:40 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/06 14:31:01 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) < 1)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] && (i + j) < len)
		{
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				j++;
				if (!(needle[j]))
					return ((char*)&haystack[i]);
			}
			j = 0;
			i++;
		}
	}
	return (NULL);
}

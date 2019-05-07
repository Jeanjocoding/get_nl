/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:19:49 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/12 15:48:27 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	unsigned int	i;
	unsigned char	c2;

	i = 0;
	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	c2 = (unsigned char)c;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == c2)
			return (&cdst[i + 1]);
		i++;
	}
	return (NULL);
}

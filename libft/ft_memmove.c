/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:31:47 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/12 17:36:42 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned char		*src1;
	size_t				i;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	i = 0;
	if (dst1 < src1)
	{
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else
	{
		while (len)
		{
			len--;
			dst1[len] = src1[len];
		}
	}
	return ((unsigned char*)dst);
}

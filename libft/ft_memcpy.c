/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:08:26 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/06 14:34:52 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*strz1;
	const char	*strz2;
	size_t		i;

	strz1 = (char*)dst;
	strz2 = (const char*)src;
	i = 0;
	while (i < n)
	{
		strz1[i] = strz2[i];
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:56:41 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/08 15:02:43 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*strz;

	i = 0;
	strz = (unsigned char*)b;
	while (i < len)
	{
		strz[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

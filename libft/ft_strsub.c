/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:41:04 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/17 12:52:21 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*mlc;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(mlc = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		mlc[i] = s[start];
		i++;
		start++;
	}
	mlc[i] = '\0';
	return (mlc);
}

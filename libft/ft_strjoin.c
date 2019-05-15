/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:21:05 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/15 11:03:07 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*scat;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	scat = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (scat == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		scat[j] = *s1++;
		j++;
	}
	while (s2[i])
	{
		scat[j] = s2[i];
		i++;
		j++;
	}
	scat[j] = '\0';
	return (scat);
}

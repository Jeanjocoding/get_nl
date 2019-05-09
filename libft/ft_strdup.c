/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:56:35 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/09 16:22:12 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*mlc;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (!(mlc = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		mlc[i] = s1[i];
		i++;
	}
	mlc[i] = '\0';
	return (mlc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:59:34 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/07 17:37:09 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strextract(char const *s, char c, unsigned int index)
{
	char			*mlc;
	unsigned int	i;
	unsigned int	start;

	i = 0;
	if (s == NULL)
		return (NULL);
	start = index;
	while (s[index] != c)
		index++;
	if (!(mlc = ft_strnew(index - start)))
		return (NULL);
	while (s[start] != c)
	{
		mlc[i] = s[start];
		i++;
		start++;
	}
	mlc[i] = '\0';
	return (mlc);
}

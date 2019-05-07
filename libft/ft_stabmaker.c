/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stabmaker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:50:30 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/10 14:51:30 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_stabmaker(size_t len)
{
	char			**stab;
	unsigned int	i;

	i = 0;
	if (!(stab = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		stab[i] = 0;
		i++;
	}
	stab[i] = 0;
	return (stab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:20:08 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/10 18:32:08 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		negcheck(int nbr)
{
	int	check;

	check = 0;
	if (nbr == -2147483648)
		return (2);
	if (nbr < 0)
		check = 1;
	return (check);
}

void			ft_putnbr(int nbr)
{
	if (negcheck(nbr) == 2)
		ft_putstr("-2147483648");
	else
	{
		if (negcheck(nbr) == 1)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr >= 10)
		{
			ft_putnbr(nbr / 10);
			ft_putchar((nbr % 10) + '0');
		}
		else
			ft_putchar((nbr % 10) + '0');
	}
}

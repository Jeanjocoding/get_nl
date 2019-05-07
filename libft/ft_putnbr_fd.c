/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:52:04 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/10 18:52:13 by tlucille         ###   ########.fr       */
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

void			ft_putnbr_fd(int nbr, int fd)
{
	if (negcheck(nbr) == 2)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (negcheck(nbr) == 1)
		{
			ft_putchar_fd('-', fd);
			nbr = -nbr;
		}
		if (nbr >= 10)
		{
			ft_putnbr_fd((nbr / 10), fd);
			ft_putchar_fd(((nbr % 10) + '0'), fd);
		}
		else
			ft_putchar_fd(((nbr % 10) + '0'), fd);
	}
}

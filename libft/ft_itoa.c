/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:00 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/16 19:15:12 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		neg_check(int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

static int		itoa_counter(int nb)
{
	int	count;

	count = 0;
	if (neg_check(nb) == 1)
	{
		count++;
		nb = -nb;
	}
	while ((nb / 10) > 0)
	{
		count++;
		nb = nb / 10;
	}
	count++;
	return (count);
}

char			*ft_itoa(int n)
{
	char	*mlc;
	int		n_char;
	int		nb;

	nb = n;
	n_char = itoa_counter(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (neg_check(n) == 1)
		n = -n;
	if (!(mlc = ft_strnew(n_char)))
		return (NULL);
	mlc[n_char] = '\0';
	while (--n_char > 0)
	{
		mlc[n_char] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg_check(nb) == 1)
		mlc[0] = '-';
	else
		mlc[0] = (n % 100) + '0';
	return (mlc);
}

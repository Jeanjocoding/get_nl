/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:12:48 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/23 13:02:46 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		make_return(unsigned long long ul, long long int check, int len)
{
	if (len > 19 && check > 0)
		return (-1);
	if (len > 19 && check < 0)
		return (0);
	if (ul > 9223372036854775807 && check > 0)
		return (-1);
	if (ul == 9223372036854775807 && check < 0)
		return (0);
	return ((long long int)ul);
}

int				ft_atoi(const char *str)
{
	unsigned long int	i;
	long long int		nb;
	long long int		check;
	int					len;

	nb = 0;
	i = 0;
	check = 1;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			check = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (check * (long long int)(str[i] - '0'));
		i++;
		len++;
	}
	return (make_return((unsigned long long)nb, check, len));
}

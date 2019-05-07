/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:41:35 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/17 12:31:21 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	char	*schar;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (NULL);
	schar = (char*)s;
	str = ft_strnew(ft_strlen(schar));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(schar[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

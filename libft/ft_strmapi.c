/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:31:29 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/17 12:46:28 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*schar;

	if (f == NULL || s == NULL)
		return (NULL);
	schar = (char*)s;
	str = ft_strnew(ft_strlen(schar));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, schar[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

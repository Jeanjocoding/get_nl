/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:20:04 by tlucille          #+#    #+#             */
/*   Updated: 2019/04/24 16:46:51 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*mlc;
	unsigned int	i;
	unsigned int	j;

	mlc = NULL;
	i = 0;
	if (s == NULL)
		return (mlc);
	if (ft_strlen(s) < 1)
		return (ft_strnew(1));
	j = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i == ft_strlen(s))
		return (ft_strnew(1));
	while (s[j] && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	j++;
	if (!(mlc = ft_strsub(s, i, (size_t)(j - i))))
		return (NULL);
	return (mlc);
}

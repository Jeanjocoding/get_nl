/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:43:15 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/21 16:36:09 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"

int			ft_strlenc(char *s, int c)
{
	int		i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (0);
}


t_list		*bp_last_line(t_list **list, char **buf, int len)
{
	(*list)->rest = NULL;
	if (len > 0)
	{
		if (!((*list)->line = ft_strdup(*buf)))
			return (NULL);
		(*list)->complet = 2;
	}
	else
	{
		(*list)->line = NULL;
		(*list)->complet = 1;
	}
	ft_memdel((void**)buf);
	return (*list);
}

t_list		*buf_parser(char **buf, int len, int lenc)
{
	int		i;
	t_list	*list;
	char	line[lenc + 1];
	char	rest[len - lenc];

	i = 0;
	list = NULL;
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	list->complet = 0;
	if (ft_strchr(*buf, '\n') != NULL)
	{
		list->line = ft_strsub(*buf, 0, lenc);
		if (lenc < len - 1)
			list->rest = ft_strncpy(rest, &((*buf)[lenc]), (len + 1) - lenc);
		else
			list->rest = NULL;
		ft_memdel((void**)buf);
		return (list);
	}
	else
		return (bp_last_line(&list, buf, len));
}

t_list		*line_finder(char **pline, int fd)
{
	char	*join;
	char	*temp;
	char	buf[BUFF_SIZE + 1];
	int		ret[2];

	ret[0] = 10;
	join = NULL;
	temp = ft_strchr(*pline, '\n');
	while (temp == NULL && ret[0] > 0)
	{
		ret[0] = read(fd, buf, BUFF_SIZE);
		if (ret[0] == -1)
			return (NULL);
		else if (ret[0] > 0)
		{
			buf[ret[0]] = '\0';
			if (!(join = ft_strjoin(*pline, buf)))
				return (NULL);
			ft_memdel((void**)pline);
			*pline = join;
			temp = ft_strchr((char*)buf, '\n');
		}
	}
	ret[0] = ft_strlen(*pline);
	ret[1] = ft_strlenc(*pline, '\n');
	return (buf_parser(pline, ret[0], ret[1]));
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*prev[MAX_FD];
	t_list			*actual;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || fd > 7168 || BUFF_SIZE < 1 || line
			== NULL || read(fd, buf, 0) == -1)
		return (-1);
	if ((prev[fd] == NULL || prev[fd]->rest == NULL))
	{
		if (prev[fd] == NULL)
			if (!(prev[fd] = (t_list*)malloc(sizeof(t_list))))
				return (-1);
		(prev[fd])->rest = ft_strnew(1);
		(prev[fd])->complet = 0;
	}
	if (prev[fd]->complet == 2)
		return (0);
	if (!(actual = line_finder(&prev[fd]->rest, fd)))
		return (-1);
	if (actual->complet == 1)
	{
//		ft_memdel((void**)actual);
		return (0);
	}
	*line = actual->line;
	ft_memdel((void**)&prev[fd]);
	prev[fd] = actual;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:43:15 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/21 17:17:28 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"

t_list		*bp_last_line(t_list **list, char **buf)
{
	(*list)->rest = NULL;
	if (ft_strlen(*buf) > 0)
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

t_list		*buf_parser(char **buf)
{
	int		i;
	t_list	*list;

	i = 0;
	list = NULL;
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	list->complet = 0;
	if (ft_memchr(*buf, '\n', ft_strlen(*buf)) != NULL)
	{
		if (!(list->line = ft_strextract(*buf, '\n', 0)))
			return (NULL);
		if (ft_strlen(list->line) < ft_strlen(*buf))
		{
			if (!(list->rest = ft_strextract(ft_strchr(*buf, '\n'), '\0', 1)))
				return (NULL);
		}
		else
			list->rest = NULL;
		ft_memdel((void**)buf);
		return (list);
	}
	else
		return (bp_last_line(&list, buf));
}

t_list		*line_finder(char **pline, int fd)
{
	char	*join;
	char	*temp;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	ret = 10;
	join = NULL;
	temp = ft_strchr(*pline, '\n');
	while (temp == NULL && ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (NULL);
		else if (ret > 0)
		{
			buf[ret] = '\0';
			if (!(join = ft_strjoin(*pline, buf)))
				return (NULL);
			ft_memdel((void**)pline);
			*pline = join;
			temp = ft_strchr((char*)buf, '\n');
		}
	}
	return (buf_parser(pline));
}

int			free_last(t_list **list)
{
	ft_memdel((void**)list);
	return (0);
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
		return (free_last(&actual));
	*line = actual->line;
	ft_memdel((void**)&prev[fd]);
	prev[fd] = actual;
	return (1);
}

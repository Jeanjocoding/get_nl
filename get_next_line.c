#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

// idee pour gagner lignes sur line_finder: mettre ret en parametre
// faire fonction pour free g_list et retourner null
//
//
//il faut reussir a faire en sorte que si ligne pas terminee par \n la ligne soit quand meme ecrite et que la fonc renvoie 1
//
//ca peut se faire en remplacant stop par un booleen indiquant si ret = 0 ou non. on met ensuite ce booleen en parametre du buf parser qui du coup retournera la structure complete avec un stop a 0

//probleme: get se relance alors que prev[fd] complet = 2

// check line null, buf size < 1 et read blanc

g_list		*buf_parser(char **buf, int stop)
{
	int	i;
	g_list	*list;

	i = 0;
	list = NULL;
	if (!(list = (g_list*)malloc(sizeof(g_list))))
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
	}
	else if (stop == 1 && ft_strlen(*buf) > 0)
	{
		list->rest = NULL;
		list->complet = 2;
		if (!(list->line = ft_strdup(*buf)))
			return (NULL);
		ft_memdel((void**)buf);
	}
	else if (stop == 1 && ft_strlen(*buf) == 0)
	{
		list->line = NULL;
		list->rest = NULL;
		list->complet = 1;
	}
	return (list);
}

g_list		*line_finder(char **pline, int fd)
{
	char	*join;
	char	*temp;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		stop;

	ret = 10;
	stop = 0;
	join = NULL;
//	temp = ft_strextract(ft_strchr(*pline, '\n'), '\0', 1);
	temp = ft_strchr(*pline, '\n');
	while (temp == NULL && ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0)
			stop = 1;
		else if (ret == -1)
			return (NULL);
		else if (ret > 0)
		{
			buf[ret] = '\0';
			if (!(join = ft_strjoin(*pline, buf)))
				return (NULL);
			ft_memdel((void**)pline);
			*pline = join;
//			temp = ft_strextract(ft_strchr((char*)buf, '\n'), '\0', 1);
			temp = ft_strchr((char*)buf, '\n');
		}
	}
//	ft_memdel((void**)&temp);
	return (buf_parser(pline, stop));
}

int	get_next_line(const int fd, char **line)
{
	static g_list	*prev[MAX_FD];
	g_list		*actual;
	char 		buf[BUFF_SIZE + 1];

	actual = NULL;
	if (fd < 0 || fd > 7168  || line == NULL || read(fd, buf, 0) == -1)
		return (-1);
	if ((prev[fd] == NULL || prev[fd]->rest == NULL))
	{
		if (prev[fd] == NULL)
			if (!(prev[fd] = (g_list*)malloc(sizeof(g_list))))
				return (-1);
		(prev[fd])->rest = ft_strnew(1);
		(prev[fd])->complet = 0;
	}
	if (prev[fd]->complet == 1 || prev[fd]->complet == 2)
		return (0);
	if (!(actual = line_finder(&prev[fd]->rest, fd)))
		return (-1);
	if (actual->complet == 1)
		return (0);
	*line = actual->line;
	ft_memdel((void**)&prev[fd]);
	prev[fd] = actual;
	return (1);
}

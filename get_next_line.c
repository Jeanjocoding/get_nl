#include "libft.h"
#include "get_next_line.h"

// idee pour gagner lignes sur line_finder: mettre ret en parametre
// faire fonction pour free g_list et retourner null
//
//
//il faut reussir a faire en sorte que si ligne pas terminee par \n la ligne soit quand meme ecrite et que la fonc renvoie 1
//
//ca peut se faire en remplacant stop par un booleen indiquant si ret = 0 ou non. on met ensuite ce booleen en parametre du buf parser qui du coup retournera la structure complete avec un stop a 0

g_list		*buf_parser(void *buf, int stop)
{
	int	i;
	g_list	*list;

	i = 0;
//	printf("buf : %s\n", buf);
	if (!(list = (g_list*)malloc(sizeof(g_list*))))
		return (NULL);
	if (ft_memchr(buf, '\n', ft_strlen((char*)buf)) != NULL)
	{
		if (!(list->line = ft_strextract((char*)(buf), '\n', 0)))
			return (NULL);
		if (ft_strlen((char*)list->line) < ft_strlen((char*)buf))
		{
			if (!(list->rest = ft_strextract(ft_strchr((char*)buf, '\n'), '\0', 1)))
				return (NULL);
		}
		else
			list->rest = NULL;
	}
	else if (stop == 0)
	{
		list->line = NULL;
		if (!(list->rest = ft_strdup((char*)buf)))
			return (NULL);
	}
	else if (stop == 1 && ft_strlen(buf) > 0)
	{
		if (!(list->line = ft_strdup((char*)buf)))
			return (NULL);
		list->complet = 2;
	}
	else if (stop == 1 && ft_strlen(buf) == 0)
	{
		list->line = NULL;
		list->complet = 1;
	}
	return (list);
}

g_list		*line_finder(char *pline, int fd)
{
	char	*join;
	char	*temp;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		stop;

	ret = 10;
	stop = 0;
	temp = ft_strextract(ft_strchr((char*)pline, '\n'), '\0', 1);
	while (temp == NULL && ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0)
			stop = 1;
		else
		{
			buf[ret] = '\0';
			if (!(join = ft_join_free(pline, ft_strdup((char*)buf))))
				return (NULL);
			pline = join;
			temp = ft_strextract(ft_strchr((char*)buf, '\n'), '\0', 1);
		}
	}
	return (buf_parser(pline, stop));
}

int	get_next_line(const int fd, char **line)
{
	static g_list	*prev[MAX_FD];
	g_list		*actual;

	if (!(actual = (g_list*)malloc(sizeof(g_list*))))
		return (-1);
	if (prev[fd] == NULL || prev[fd]->rest == NULL)
	{
		if (!(prev[fd] = (g_list*)malloc(sizeof(g_list*))))
			return (-1);
		prev[fd]->rest = ft_strnew(1);
	}
	if (!(actual = line_finder(prev[fd]->rest, fd)))
		return (-1);
	if (actual->complet == 1 )
		return (0);
	*line = actual->line;
	free(prev[fd]);
	prev[fd] = actual;
	return (1);
}

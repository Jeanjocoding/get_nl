#include "libft.h"
#include "get_next_line.h"

// idee pour gagner lignes sur line_finder: mettre ret en parametre
// faire fonction pour free g_list et retourner null
//
//
//il faut reussir a faire en sorte que si ligne pas terminee par \n la ligne soit quand meme ecrite et que la fonc renvoie 1
//
//ca peut se faire en remplacant stop par un booleen indiquant si ret = 0 ou non. on met ensuite ce booleen en parametre du buf parser qui du coup retournera la structure complete avec un stop a 0

//probleme: get se relance alors que prev[fd] complet = 2

g_list		*buf_parser(char *buf, int stop)
{
	int	i;
	g_list	*list;

	i = 0;
	printf("%s\n", " ");
	printf("%s\n", " ");
	printf("%s\n", "########entree dans le parser ");
	printf("buf : %s\n", buf);
	if (!(list = (g_list*)malloc(sizeof(g_list*))))
		return (NULL);
	printf("buf_len : %zu\n", ft_strlen(buf));
	if (ft_memchr(buf, '\n', ft_strlen(buf)) != NULL)
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
//	else if (stop == 0)
//	{
//		list->line = NULL;
//		if (!(list->rest = ft_strdup((char*)buf)))
//			return (NULL);
//	}
	else if (stop == 1 && ft_strlen(buf) > 0)
	{
		printf("buf if len est sup a 0 : %s\n", buf);
//		if (!(list->line = ft_strdup((char*)buf)))
//		{
//			printf("%s\n", "alloc fail");
//			return (NULL);
//		}
//		printf("line if len > 0 : %s\n", list->line);
		list->rest = NULL;
		if (!(list->complet = (int)malloc(sizeof(int))))
			return (NULL);
		list->complet = 2;
		stop = 20;
//		list->line = ft_strextract(buf, '\0', 0);
		list->line = ft_strdup(buf);
		printf("dup_test : %s\n", ft_strdup(buf));
//		list->line = ft_strnew(ft_strlen(buf));
//		list->line = ft_strnew(ft_strlen(buf));
//		ft_strcpy(list->line, buf);
		printf("line in boucle : %s\n", list->line);
	}
	else if (stop == 1 && ft_strlen(buf) == 0)
	{
		printf("buf if len = 0 : %s\n", buf);
		list->line = NULL;
		list->complet = 1;
	}
//	printf("%s\n\n", " ");
//	printf("line : %s\n", list->line);
//	printf("rest : %s\n", list->rest);
//	printf("complet : %d\n", list->complet);
	printf("%s\n", "###########sortie du parser ");
//	printf("%s\n\n", " ");
//	if (stop == 20)
//		list->line = ft_strdup((char*)buf);
	return (list);
}

g_list		*line_finder(char *pline, int fd)
{
	char	*join;
	char	*temp;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		stop;

	printf("%s\n\n", " ");
	printf("%s\n\n", "########entree dans le finder ");
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
	printf("pline =  %s\n", pline);
	printf("stop =  %d\n", stop);
	printf("%s\n\n", " ");
	printf("%s\n\n", "########sortie du finder ");
	return (buf_parser(pline, stop));
}

int	get_next_line(const int fd, char **line)
{
	static g_list	*prev[MAX_FD];
	g_list		*actual;

	printf("new turn, prev->line =  %s\n", "slt");
	printf("new turn, prev->rest=  %s\n", "slt");
	if (!(actual = (g_list*)malloc(sizeof(g_list*))))
		return (-1);
	if ((prev[fd] == NULL || prev[fd]->rest == NULL))
	{
		printf("préjen =  %s\n", "je viens la");
//		printf("complet =  %d\n", prev[fd]->complet);
		if (prev[fd] == NULL)
		{
			if (!(prev[fd] = (g_list*)malloc(sizeof(g_list*))))
				return (-1);
		}
		prev[fd]->rest = ft_strnew(1);
	}
	if (prev[fd]->complet == 1 || prev[fd]->complet == 2)
		return (0);
	printf("prev->complet  %d\n", prev[fd]->complet);
	if (!(actual = line_finder(prev[fd]->rest, fd)))
		return (-1);
	if (actual->complet == 1 )
		return (0);
	*line = actual->line;
	free(prev[fd]);
	prev[fd] = actual;
	return (1);
}

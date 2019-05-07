#include "libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line);

int	main(void)
{
	int	fd;
	int	fd2;
	g_list	*list;
	char	buf[BUFF_SIZE + 1];
	char	pline[] = "hey";
	char	*bjr = NULL;
	int		i;
	i = 0;


	fd = open("bjr", O_RDONLY);
//	fd2 = open("test2.txt", O_RDONLY);

	//	read(fd, buf, BUF_SIZE);
	//	buf[BUF_SIZE] = '\0';
	//	list = line_finder("hey\ndfgefge\0", fd);
	//	printf("line : %s\n", list->line);
	//	printf("rest : %s\n", list->rest);
	//	return (0);
//	printf("gnl : %d\n", get_next_line(fd, &bjr));
//	printf("real 2 : %s\n", bjr);
	get_next_line(fd, &bjr);
	printf("real 3 : %s\n", bjr);
	return (0);
	get_next_line(fd, &bjr);
	printf("real 3 : %s\n", bjr);
	get_next_line(fd2, &bjr);
	printf("real 3 : %s\n", bjr);
	get_next_line(fd, &bjr);
	printf("real 3 : %s\n", bjr);
	get_next_line(fd2, &bjr);
	printf("real 3 : %s\n", bjr);
	get_next_line(fd, &bjr);
	printf("real 3 : %s\n", bjr);
	return (0);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	get_next_line(fd, &bjr);
	printf("real 3 : %s\n", bjr);
	get_next_line(fd, &bjr);
	printf("real 3 : %s\n", bjr);
	get_next_line(fd, &bjr);
	printf("real 3 : %s\n", bjr);
	get_next_line(fd, &bjr);
	printf("real 3 : %s\n", bjr);
	//  	read(fd, buf, BUF_SIZE);
	//	buf[BUF_SIZE] = '\0';
	//	list = line_finder(pline, fd);
	//	//printf("rest : %s\n", list->rest);
}




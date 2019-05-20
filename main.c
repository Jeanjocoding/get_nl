#include "libft/includes/libft.h"
#include "get_next_line.h"
#include "stdio.h"

int		get_next_line(const int fd, char **line);

int	main(int ac, char **av)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	ret1 = 10;
	int	ret2 = 10;
	int	ret3 = 10;
	char	*l1;
	char	*l2;
	char	*l3;

	(void)ac;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = 0; // open(av[3], O_RDONLY);
	while (ret1 > 0 || ret2 > 0 || ret3 > 0)
	{
		printf("\033[1;32m"); 
		ret1 = get_next_line(fd1, &l1);
		printf("line_fd1 : %s\n", l1);
		printf("return value fd1 : %d\n\n", ret1);
		printf("\033[01;33m"); 
		ret2 = get_next_line(fd2, &l2);
		printf("line_fd2 : %s\n", l2);
		printf("return value fd2: %d\n\n", ret2);
		printf("\033[1;34m"); 
		ret3 = get_next_line(fd3, &l3);
		printf("line_fd3 : %s\n", l3);
		printf("return value fd3: %d\n\n", ret3);
		printf("\033[0m"); 
		printf("################################## %s\n\n", "");
		l1 = NULL;
		l2 = NULL;
		l3 = NULL;
	}
	printf("\033[0m"); 
	close(fd1);
	close(fd2);
	close(fd3);
}




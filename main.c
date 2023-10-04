#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int		ft_atoi_base(char *str, char *base);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern int		ft_strlen(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dest, const char *src);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char		*ft_strdup(const char *s);


void	test_strdup(char *src)
{
	char	*dest;

	dest = strdup(src);
	printf("dest = %s\n", dest);
	free(dest);
	
	dest = ft_strdup(src);
	printf("dest = %s\n", dest);
	free(dest);
}

void	test_read(char *path, int count)
{
	int fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("invalid path\n");
		return ;
	}

	char	*dest = calloc(count + 1, 1);
	if (!dest)
		return ;
	printf("read = returns %zu\n", read(fd, dest, count));
	printf("dest contain .-%s-.\n", dest);
	perror("read errno = ");
	errno = 0;
	free(dest);
	close(fd);

	fd = open(path, O_RDONLY);
	dest = calloc(count + 1, 1);
	if (!dest)
		return ;
	printf("ft_read = returns %zu\n", ft_read(fd, dest, count));
	printf("dest contain .-%s-.\n", dest);
	perror("ft_read errno = ");
	errno = 0;
	free(dest);
	close(fd);
}

void	test_write_fd(char *path, char *src, int count)
{
	int fd = open(path, O_APPEND | O_WRONLY);
	if (fd < 0)
	{
		printf("invalid path\n");
		return ;
	}
	printf("write returns %zu\n", write(fd, src, count));
	perror("write errno = ");
	errno = 0;
	close(fd);

	fd = open(path, O_APPEND | O_WRONLY);
	printf("ft_write returns %zu\n", ft_write(fd, src, count));
	perror("ft_write errno = ");
	errno = 0;
	close(fd);
}
void	test_write(int fd, char *src, int count)
{
	printf("write returns %zu\n", write(fd, src, count));
	perror("write errno ");
	errno = 0;

	write(1, "\n", 1);
	printf("ft_write returns %zu\n", ft_write(fd, src, count));
	perror("ft_write errno ");
	errno = 0;
}

void	test_strcmp(char *s1, char *s2)
{
	printf("strcmp = %d \n", strcmp(s1, s2));
	printf("ft_strcmp = %d \n", ft_strcmp(s1, s2));
}

void	test_strcpy(char *str)
{
	char	*dest;
	int i	= ft_strlen(str);
	
	dest = calloc(i + 1, 1);
	if (!dest)
		return ;
	dest = strcpy(dest, str);
	if (str)
		printf("strcpy = .-%s-...-%s-.\n", dest, str);
	else
		printf(".-%s-.\n", dest);
	free(dest);

	dest = calloc(i + 1, 1);
	if (!dest)
		return ;
	dest = ft_strcpy(dest, str);
	if (str)
		printf("ft_strcpy = .-%s-...-%s-.\n", dest, str);
	else
		printf(".-%s-.\n", dest);
	free(dest);

	char	dest2[1000];
	
	ft_strcpy(dest2, str);
	if (dest2[ft_strlen(str)] == 0)
		printf("good\n");
}


void	test_strlen(char *str)
{
	if (str == NULL)
	{
		printf("strlen segv\n");
		return ;
	}
	printf("len of strlen:%lu\n", strlen(str));
	printf("len of ft_strlen:%d\n", ft_strlen(str));
}

int    main(int ac, char **av)
{
/*	if (ac != 8)
	{
		printf("rentrer %d arguments dans cet ordre : une chaine, une chaine a comparer, un fd, une chaine a ecrire dans le fd, ", 7);
		printf("la taille quelle est supposee faire, le path vers un fichier, le nombre de byte a y lire" );
		return (0);
	}

	if (!strcmp(av[1], "NULL"))
		av[1] = NULL;
	test_strlen(av[1]);
	test_strcpy(av[1]);	
	test_strcmp(av[1], av[2]);	
	test_write(atoi(av[3]), av[4], atoi(av[5]));
	test_write_fd(av[6], av[4], atoi(av[5]));
	test_read(av[6], atoi(av[7]));
	test_strdup(av[1]);
*/

	(void)ac;

	printf("%d\n", ft_atoi_base(av[1], av[2]));
	return (0);
}

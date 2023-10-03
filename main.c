#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern int		ft_strlen(char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dest, const char *src);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char		*ft_strdup(const char *s);


int    main(int ac, char **av)
{
	(void)ac;
	char	*dest;
	int i;
    
//	printf("size:%d\n", ft_strlen(av[1]));
	if (av[1])
		i = ft_strlen(av[1]);
	else 
		i = 2;
	dest = calloc(i + 1, 1);
	if (!dest)
		return (1);
	dest = ft_strcpy(dest, av[1]);
	if (av[1])
		printf(".-%s-...-%s-.\n", dest, av[1]);
	else
		printf(".-%s-.\n", dest);
	free(dest);
	
//	printf("true = %d \n", strcmp(NULL, NULL));
//	printf("fasl = %d \n", ft_strcmp(NULL, NULL));
//	printf("true = %d \n", strcmp(av[1], av[2]));
//	printf("fasl = %d \n", ft_strcmp(av[1], av[2]));
/*	printf("%d = ", ft_write(1, NULL, 1));
	perror("ft_NULL = ");	
	printf("%d = ", write(1, NULL, 1));
	perror("NULL = ");	

	printf("%d = ", ft_write(atoi(av[1]), av[2], atoi(av[3])));
		
	perror("ftwrite = ");
	printf("%d = ", write(atoi(av[1]), av[2], atoi(av[3])));
	perror("write = ");
*/
	
//	char	ft_buffer[123];
//	char	buffer[123];

/*	printf("%d = ", ft_read(1, NULL, 1));
	perror("ft_NULL = ");	
	printf("%d = ", read(1, NULL, 1));
	perror("NULL = ");	
*/
/*
	int fd = open("/mnt/nfs/homes/ccottin/Documents/libasm/Makefile", O_RDONLY);
	if (fd < 0)
	{
		perror("truc");
		exit(0);
	}
	printf("fd = %d\n ", fd);
	printf("ft -> %d = %s\n", ft_read(fd, ft_buffer, atoi(av[1])), ft_buffer);	
	perror("ftread = ");
	close(fd);
	fd = open("/mnt/nfs/homes/ccottin/Documents/libasm/Makefile", O_RDONLY);
	printf(" -> %d = %s\n", read(fd, buffer, atoi(av[1])), buffer);	
	perror("read = ");
	close(fd);
*/

//	char	*dest;
	
	dest = strdup(av[1]);
	printf("dest = %s\n", dest);
	free(dest);
	dest = ft_strdup(av[1]);
	printf("dest = %s\n", dest);
	free(dest);


	return (0);
}

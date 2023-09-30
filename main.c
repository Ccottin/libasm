#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 #include <unistd.h>

extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern int		ft_strlen(char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dest, const char *src);

int    main(int ac, char **av)
{
	(void)ac;
//	char	*dest;
//	int i;
    
//	printf("size:%d\n", ft_strlen(av[1]));
/*	if (av[1])
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
	*/
//	printf("true = %d \n", strcmp(NULL, NULL));
//	printf("fasl = %d \n", ft_strcmp(NULL, NULL));
//	printf("true = %d \n", strcmp(av[1], av[2]));
//	printf("fasl = %d \n", ft_strcmp(av[1], av[2]));
	
	ft_write(atoi(av[1]), av[2], atoi(av[3]));
	perror("ftwrite = ");
	write(atoi(av[1]), av[2], atoi(av[3]));
	perror("write = ");

	return (0);
}

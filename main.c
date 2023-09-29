#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int		ft_strlen(char *s);
extern int		ft_strcmp(char *s1, char *s2);
extern char		*ft_strcpy(char *dest, char *src);

int    main(int ac, char **av)
{
	(void)ac;
//	char	*dest;
//	int i;
    
	//printf("size:%d\n", ft_strlen(av[1]));
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
	printf("true = %d \n", strcmp(av[1], av[2]));
	printf("fasl = %d \n", ft_strcmp(av[1], av[2]));

	return (0);
}

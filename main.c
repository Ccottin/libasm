#include <stdio.h>
#include <stdlib.h>

extern int		ft_strlen(char *s);
extern char		*ft_strcpy(char *dest, char *src);

int    main(int ac, char **av)
{
	(void)ac;
	char	*dest;
    //printf("size:%d\n", ft_strlen(av[1]));
	dest = calloc(ft_strlen(av[1]) + 1, 1);
	if (!dest)
		return (1);
	dest = ft_strcpy(dest, av[1]);
    printf(".-%s-...-%s-.\n", dest, av[1]);
	free(dest);
	return (0);
}

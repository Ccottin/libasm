#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

extern char * ft_strcpy(char *dest, const char *src);
extern int ft_strlen(char *s);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern	ssize_t ft_read(int fd, void *buf, size_t count);
extern  char *ft_strdup(const char *s);

void	check_strcpy(char *src, int num)
{
	char	dest[100];
	
	if (!memcmp(ft_strcpy(dest, src), src, strlen(src) + 1))
		printf("Test%d: OK\n", num);
	else
		printf("Test%d: FALSE\nsrc:%s\nres:%s\n", num, src, ft_strcpy(dest, src));
}

void	test_ft_strcpy(void)
{
	char	*src;
	int		i = 1;

	src = "coucou";
	check_strcpy(src, i++);
	src = "";
	check_strcpy(src, i++);
//	src = NULL;
//	check_strcpy(src, i++);
	src = "1";
	check_strcpy(src, i++);
	src = "12";
	check_strcpy(src, i++);
	src = "12345678";
	check_strcpy(src, i++);
}

void	check_strcmp(char *s1, char *s2, int test)
{
	int	a;
	int	b;

	a = strcmp(s1, s2);
	b = ft_strcmp(s1, s2);
	if (a == b || (a < 0 && b < 0) || (a > 0 && b > 0))
		printf("Test%d: OK\n", test);
	else
		printf("Test%d: FALSE\ns1:%s\ns2:%s\nstrcmp:%d\nft_strcmp:%d\n", test, s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));

}
void	test_ft_strcmp()
{
	char	*s1;
	char	*s2;

	s1 = "sl";
	s2 = "slo";
	check_strcmp(s1, s2, 1);
	check_strcmp(s2, s1, 2);
	s1 = "";
	s2 = "42";
	check_strcmp(s1, s2, 3);
	check_strcmp(s2, s1, 4);
	s2 = "";
	check_strcmp(s1, s2, 5);
	s1 = "4242";
	s2 = "4242";
	check_strcmp(s1, s2, 6);
	s1 = "lo";
	s2 = "slo";
	check_strcmp(s1, s2, 7);
	check_strcmp(s2, s1, 8);
	s1 = "NULL";
	check_strcmp(s1, s2, 9);
	check_strcmp(s1, s1, 10);
	check_strcmp(s2, s1, 11);
	s1 = "\0";
	s2 = "\0\0";
	check_strcmp(s1, s2, 12);
	check_strcmp(s2, s1, 13);

}


void	check_ft_strdup(char *src, int test, int len)
{
	char	*dest;
	char	*dest2;

	dest = strdup(src);
	dest2 = ft_strdup(src);
	if (!strncmp(dest, dest2, len))
		printf("Test%d: OK\n", test);
	else
		printf("Test%d: FALSE\nsrc:%s\nres:%s\n", test, src, dest2);
	free(dest);
	free(dest2);
}

void	test_ft_strdup(void)
{
	int	i = 1;

	check_ft_strdup("", i++, strlen("") + 1);
	check_ft_strdup("coucou", i++, strlen("coucou") + 1);
//	check_ft_strdup(NULL, i++, 1);
	check_ft_strdup("12345678912345789123456789", i++, strlen("12345678912345789123456789") + 1);
	check_ft_strdup("\n", i++, strlen("\n") + 1);
	check_ft_strdup("1", i++, strlen("1") + 1);

	char		tab[42];
	tab[41] = 41;
	check_ft_strdup(tab, i++, 42);
	tab[41] = 0;
	check_ft_strdup(tab, i++, 42);
	int		tabe[42];
	tabe[41] = 41;
	check_ft_strdup(tabe, i++, 168);
	tabe[41] = 0;
	check_ft_strdup(tabe, i++, 168);
}
/*
void    write_checks(void *buffer, size_t size)
{
    int	fd;
	int	fd1;	
    int	res;
	int	write_sys;
	int my_write;
	int errno_sys;
	int my_errno;

    fd = open("test0", O_CREAT | O_RDWR);
    fd1 = open("test1", O_CREAT | O_RDWR);
    write_sys = write(fd, buffer, size);
    errno_sys = errno;
    my_write = ft_write(fd1, buffer, size);
    my_errno = errno;
    lseek(fd, 0, SEEK_SET);
    lseek(fd1, 0, SEEK_SET);

    char    buffer0[size + 1];
    char    buffer1[size + 1];
    bzero(buffer, size);
    if (read(fd, buffer0, size) < 0)
    {
        perror("read");
        return;
    }
    if (read(fd1, buffer0, size) < 0)
    {
        perror("read");
        return;
    }
    close(fd);
    close(fd1);
    res = memcmp(buffer0, buffer1, size);
    if (res == 0 && errno_sys == my_errno && my_write == write_sys)
        printf("Test: OK\n");
    else
        printf("write_sys:%ld my_write:%ld\n", write_sys, my_write);
    remove("test0");
}
*/
void	check_ft_write(int fd1, int fd2, char *src, int byte, int test)
{
	char	dest[byte * 2];
	char	dest2[byte * 2];
	int		write1;
	int		write2;

	
	write1 = write(fd1, src, byte);
	int	errno1 = errno;
	errno = 0;
	write2 = ft_write(fd2, src, byte);
	int	errno2 = errno;
	
	lseek(fd1, 0, SEEK_SET);
    lseek(fd2, 0, SEEK_SET);

	read(fd1, dest, byte);
	read(fd2, dest2, byte);
	if (!strncmp(dest, dest2, byte))
		printf("Test%d: OK _ ", test);
	else
		printf("Test%d: FALSE\nwrite:%s\n res:%s\n", test, dest, dest2);
	if (write1 == write2)
		printf("RETURN OK _ " );
	else
		printf("RETURN FALSE\nwrite:%d\nres:%d\n", write1, write2);


	if (errno2 == errno1)
		printf("ERRNO OK\n");
	else
		printf("ERRNO FALSE\nwrite:%d\nres:%d\n", errno1, errno2);
	errno = 0;
}
void    test_ft_write()
{
	char	*src;
	char	*path;
	char	*path2;
	int		i = 1;
	int		flags;

	errno = 0;
	flags = O_RDWR | O_CREAT;
	path = "./test1";
	path2 = "./test2";
	int fd1 = open(path, flags);
	int fd2 = open(path2, flags);
	src = "coucou";
	check_ft_write(fd1, fd2, src, strlen(src), i++);
	lseek(fd1, 0, SEEK_SET);
    lseek(fd2, 0, SEEK_SET);
	check_ft_write(fd1, fd2, src, 7, i++);
	lseek(fd1, 0, SEEK_SET);
    lseek(fd2, 0, SEEK_SET);
	check_ft_write(fd1, fd2, src, 0, i++);
	src = "";
	check_ft_write(fd1, fd2, src, strlen(src), i++);
	lseek(fd1, 0, SEEK_SET);
    lseek(fd2, 0, SEEK_SET);

	close(fd1);
	close(fd2);


	flags = O_RDWR;
	path = "./unexistingfile";
	path2 = "./unexistingfile";
	fd1 = open(path, flags);
	fd2 = open(path2, flags);
	check_ft_write(fd1, fd2, src, strlen(src), i++);
}

void	check_ft_read(char *path, int byte, int test, int flags)
{
	char	dest[100];
	char	dest2[100];
	int		read1;
	int		read2;

	bzero(dest, 100);
	bzero(dest2, 100);
	int fd = open(path, flags);
	read1 = read(fd, dest, byte);
	int	errno1 = errno;
	lseek(fd, 0, SEEK_SET);
	read2 = ft_read(fd, dest2, byte);
	if (fd > -1)
		close(fd);
	if (!strncmp(dest, dest2, byte))
		printf("Test%d: OK _ ", test);
	else
		printf("Test%d: FALSE\nread:%s\n res:%s\n", test, dest, dest2);
	if (read1 == read2)
		printf("RETURN OK _ " );
	else
		printf("RETURN FALSE\nread:%d\nres:%d\n", read1, read2);


	if (errno == errno1)
		printf("ERRNO OK\n");
	else
		printf("ERRNO FALSE\nread:%d\nres:%d\n", errno1, errno);
	errno = 0;
}

void	test_ft_read(void)
{
	char	*path;
	
	path = "";
	check_ft_read(path, 0, 1, O_RDONLY);
	check_ft_read(path, 100, 2, O_RDONLY);
	
	path = "./Makefile";
	check_ft_read(path, 0, 3, O_RDONLY);
	check_ft_read(path, 100, 4, O_RDONLY);
	check_ft_read(path, 105, 5, O_RDONLY);
	
	path = ("./NewFile");
	check_ft_read(path, 0, 6, O_CREAT | O_RDONLY);
	check_ft_read(path, 100, 7, O_CREAT | O_RDONLY);
	check_ft_read(path, 105, 8, O_CREAT | O_RDONLY);
}

void	ft_sigsev(int signum)
{
	(void)signum;
	printf("SIGSEV\n");
	exit(1);
}

int	main()
{
	signal(11, ft_sigsev);
	
	printf("-----TESTS ft_strcpy-----\n\n");
	test_ft_strcpy();
	printf("-----TESTS ft_strcmp-----\n\n");
	test_ft_strcmp();
	printf("-----TESTS ft_write-----\n\n");
	test_ft_write();
	printf("-----TESTS ft_read-----\n\n");
	test_ft_read();
	printf("-----TESTS ft_strdup-----\n\n");
	test_ft_strdup();

	return (0);
}

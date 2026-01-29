#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libasm.h"

void test_strlen(void)
{
	char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.";
	
	printf("==> ft_strlen\n\n");
	printf("ft_strlen(\"hello\") = %zu (expected: %zu)\n", ft_strlen("hello"), strlen("hello"));
	printf("ft_strlen(\"\") = %zu (expected: %zu)\n", ft_strlen(""), strlen(""));
	printf("ft_strlen(\"42 Nice\") = %zu (expected: %zu)\n", ft_strlen("42 Nice"), strlen("42 Nice"));
	printf("ft_strlen(long_str) = %zu (expected: %zu)\n", ft_strlen(long_str), strlen(long_str));
	printf("\n");
}

void test_strcpy(void)
{
	char dest1[300];
	char dest2[300];
	char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.";

	printf("==> ft_strcpy\n\n");
	printf("ft_strcpy(\"hello\") = \"%s\" (expected: \"%s\")\n", ft_strcpy(dest1, "hello"), strcpy(dest2, "hello"));
	printf("ft_strcpy(\"\") = \"%s\" (expected: \"%s\")\n", ft_strcpy(dest1, ""), strcpy(dest2, ""));
	printf("ft_strcpy(\"42 Nice\") = \"%s\" (expected: \"%s\")\n", ft_strcpy(dest1, "42 Nice"), strcpy(dest2, "42 Nice"));
	ft_strcpy(dest1, long_str);
	strcpy(dest2, long_str);
	printf("ft_strcpy(long_str) = OK (len: %zu, expected: %zu)\n", strlen(dest1), strlen(dest2));
	printf("\n");
}

void test_strcmp(void)
{
	printf("==> ft_strcmp\n\n");
	printf("ft_strcmp(\"abc\", \"abc\") = %d (expected: %d)\n", ft_strcmp("abc", "abc"), strcmp("abc", "abc"));
	printf("ft_strcmp(\"abc\", \"abd\") = %d (expected: %d)\n", ft_strcmp("abc", "abd"), strcmp("abc", "abd"));
	printf("ft_strcmp(\"abd\", \"abc\") = %d (expected: %d)\n", ft_strcmp("abd", "abc"), strcmp("abd", "abc"));
	printf("ft_strcmp(\"\", \"\") = %d (expected: %d)\n", ft_strcmp("", ""), strcmp("", ""));
	printf("ft_strcmp(\"\", \"a\") = %d (expected: %d)\n", ft_strcmp("", "a"), strcmp("", "a"));
	printf("ft_strcmp(\"a\", \"\") = %d (expected: %d)\n", ft_strcmp("a", ""), strcmp("a", ""));
	printf("\n");
}

void test_write(void)
{
	ssize_t ret1;
	ssize_t ret2;
	int fd;

	printf("==> ft_write\n\n");
	
	printf("ft_write stdout: ");
	ret1 = ft_write(1, "hello\n", 6);
	printf("returned: %zd\n", ret1);
	
	printf("write stdout:    ");
	ret2 = write(1, "hello\n", 6);
	printf("returned: %zd\n", ret2);

	fd = open("test_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ret1 = ft_write(fd, "test file\n", 10);
		printf("ft_write(fd, ...) = %zd (expected: 10)\n", ret1);
		close(fd);
		remove("test_write.txt");
	}
	
	errno = 0;
	ret1 = ft_write(-1, "test", 4);
	printf("ft_write(-1, ...) = %zd, errno = %d (expected: -1, 9)\n", ret1, errno);
	
	errno = 0;
	ret2 = write(-1, "test", 4);
	printf("write(-1, ...) = %zd, errno = %d (expected: -1, 9)\n", ret2, errno);
	printf("\n");
}

void test_read(void)
{
	ssize_t ret1;
	ssize_t ret2;
	char buf1[100];
	char buf2[100];
	int fd;

	printf("==> ft_read\n\n");

	fd = open("test_read.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		write(fd, "hello from file", 15);
		close(fd);
	}
	fd = open("test_read.txt", O_RDONLY);
	if (fd != -1)
	{
		ret1 = ft_read(fd, buf1, 15);
		buf1[ret1] = '\0';
		printf("ft_read(fd, ...) = %zd, buf = \"%s\"\n", ret1, buf1);
		close(fd);
		remove("test_read.txt");
	}
	
	errno = 0;
	ret1 = ft_read(-1, buf1, 10);
	printf("ft_read(-1, ...) = %zd, errno = %d (expected: -1, 9)\n", ret1, errno);
	
	errno = 0;
	ret2 = read(-1, buf2, 10);
    printf("read(-1, ...) = %zd, errno = %d (expected: -1, 9)\n", ret2, errno);

    /*
    printf("Test stdin - tapez quelque chose: ");
	ret1 = ft_read(0, buf1, 50);
	buf1[ret1] = '\0';
    printf("ft_read(stdin) = %zd, buf = \"%s\"\n", ret1, buf1);
    */

	printf("\n");
}

void test_strdup(void)
{
	char *s1;
	char *s2;
	char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.";

	printf("==> ft_strdup\n\n");
	
	s1 = ft_strdup("hello");
	s2 = strdup("hello");
	printf("ft_strdup(\"hello\") = \"%s\" (expected: \"%s\")\n", s1, s2);
	free(s1);
	free(s2);
	
	s1 = ft_strdup("");
	s2 = strdup("");
	printf("ft_strdup(\"\") = \"%s\" (expected: \"%s\")\n", s1, s2);
	free(s1);
	free(s2);
	
	s1 = ft_strdup("42 Nice");
	s2 = strdup("42 Nice");
	printf("ft_strdup(\"42 Nice\") = \"%s\" (expected: \"%s\")\n", s1, s2);
	free(s1);
	free(s2);

	s1 = ft_strdup(long_str);
	s2 = strdup(long_str);
	printf("ft_strdup(long_str) len = %zu (expected: %zu)\n", strlen(s1), strlen(s2));
	free(s1);
	free(s2);
	printf("\n");
}

int main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	return 0;
}

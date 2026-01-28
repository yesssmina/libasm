#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

int main(void)
{
    char *s1;
    char *s2;

    printf("=== Test ft_strdup ===\n");
    s1 = ft_strdup("hello");
    s2 = strdup("hello");
    printf("ft_strdup(\"hello\") = \"%s\"\n", s1);
    printf("strdup(\"hello\")    = \"%s\"\n", s2);
    free(s1);
    free(s2);

    printf("\n=== Test empty string ===\n");
    s1 = ft_strdup("");
    s2 = strdup("");
    printf("ft_strdup(\"\") = \"%s\"\n", s1);
    printf("strdup(\"\")    = \"%s\"\n", s2);
    free(s1);
    free(s2);

    printf("\n=== Test 42 Nice ===\n");
    s1 = ft_strdup("42 Nice");
    s2 = strdup("42 Nice");
    printf("ft_strdup(\"42 Nice\") = \"%s\"\n", s1);
    printf("strdup(\"42 Nice\")    = \"%s\"\n", s2);
    free(s1);
    free(s2);

    return 0;
}

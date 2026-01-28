#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
    printf("ft_strcmp(\"abc\", \"abc\") = %d\n", ft_strcmp("abc", "abc"));
    printf("strcmp(\"abc\", \"abc\")    = %d\n", strcmp("abc", "abc"));

    printf("ft_strcmp(\"abc\", \"abd\") = %d\n", ft_strcmp("abc", "abd"));
    printf("strcmp(\"abc\", \"abd\")    = %d\n", strcmp("abc", "abd"));

    printf("ft_strcmp(\"abd\", \"abc\") = %d\n", ft_strcmp("abd", "abc"));
    printf("strcmp(\"abd\", \"abc\")    = %d\n", strcmp("abd", "abc"));

    printf("ft_strcmp(\"\", \"\") = %d\n", ft_strcmp("", ""));
    printf("strcmp(\"\", \"\")    = %d\n", strcmp("", ""));

    printf("ft_strcmp(\"a\", \"\") = %d\n", ft_strcmp("a", ""));
    printf("strcmp(\"a\", \"\")    = %d\n", strcmp("a", ""));

    return 0;
}

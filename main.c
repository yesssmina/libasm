#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);

int main(void)
{
    char dest1[20];
    char dest2[20];

    ft_strcpy(dest1, "hello");
    strcpy(dest2, "hello");
    printf("ft_strcpy: \"%s\"\n", dest1);
    printf("strcpy:    \"%s\"\n", dest2);

    ft_strcpy(dest1, "");
    strcpy(dest2, "");
    printf("ft_strcpy (empty): \"%s\"\n", dest1);
    printf("strcpy (empty):    \"%s\"\n", dest2);

    ft_strcpy(dest1, "42 Nice!");
    strcpy(dest2, "42 Nice!");
    printf("ft_strcpy: \"%s\"\n", dest1);
    printf("strcpy:    \"%s\"\n", dest2);

    return 0;
}

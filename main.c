#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);

int main(void)
{
    printf("ft_strlen(\"hello\") = %zu\n", ft_strlen("hello"));
    printf("strlen(\"hello\")    = %zu\n", strlen("hello"));
    
    printf("ft_strlen(\"\") = %zu\n", ft_strlen(""));
    printf("strlen(\"\")    = %zu\n", strlen(""));
    
    printf("ft_strlen(\"42 Nice\") = %zu\n", ft_strlen("42 Nice"));
    printf("strlen(\"42 Nice\")    = %zu\n", strlen("42 Nice"));
    
    return 0;
}

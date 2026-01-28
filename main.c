#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);

int main(void)
{
    ssize_t ret;

    // Test normal
    printf("=== Test ft_write ===\n");
    ret = ft_write(1, "hello from ft_write\n", 20);
    printf("Retour: %zd\n", ret);

    // Test write standard pour comparer
    printf("=== Test write ===\n");
    ret = write(1, "hello from write\n", 17);
    printf("Retour: %zd\n", ret);

    // Test erreur (fd invalide)
    printf("=== Test erreur ft_write ===\n");
    errno = 0;
    ret = ft_write(-1, "test", 4);
    printf("Retour: %zd, errno: %d\n", ret, errno);

    // Test erreur write standard
    printf("=== Test erreur write ===\n");
    errno = 0;
    ret = write(-1, "test", 4);
    printf("Retour: %zd, errno: %d\n", ret, errno);

    return 0;
}

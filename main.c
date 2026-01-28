#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

int main(void)
{
    char buf[100];
    ssize_t ret;

    // Test erreur (fd invalide)
    printf("=== Test erreur ft_read ===\n");
    errno = 0;
    ret = ft_read(-1, buf, 10);
    printf("Retour: %zd, errno: %d\n", ret, errno);

    printf("=== Test erreur read ===\n");
    errno = 0;
    ret = read(-1, buf, 10);
    printf("Retour: %zd, errno: %d\n", ret, errno);

    return 0;
}

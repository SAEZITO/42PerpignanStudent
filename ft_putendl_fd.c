#include "libft.h"

void    ft_putendl_fd(char *s, int fd)
{
    int i;

    i = 0;
    while (s[i])
        ft_putchar_fd(s[i++], fd);
    write(fd, '\n', 1);
}
#include "libft.h"

char    *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char    *str;

    i = 0;
    str = (char *)malloc(ft_strlen(s) + 1)
    if (!str  || !s || !f)
        return (NULL);
    while (i < ft_strlen(s))
        str[i] = f(i, str[i++]);
    str[i] = '\0';
    return (str);
}
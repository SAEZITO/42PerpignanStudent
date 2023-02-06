#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    unsigned int    nbr;

    if (n < 0)
    {
        nbr = (unsigned int)(n * -1);
        ft_putchar_fd('-', fd);
    }
    else
        nbr = (unsigned int)n;
    if (nbr > 9)
        ft_putnbr_fd(((char)(nbr / 10) + '0'), fd);
    ft_putchar_fd(((char)(nbr % 10) + '0'), fd);
}
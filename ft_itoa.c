/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:33:36 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/03 15:26:36 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_itoa(int n)
{
    char    *str;
    int     i;
    int     nbr;
    size_t  size;

    i = 0;
    nbr = n;
    size = 0
    if (n < 0)
    {
        nbr = -n;
        size++;
    }
    while (n)
    {
        n /= 10;
        size++;
    }
    str = (char *)malloc((size + 1));
    if (!str)
        return (NULL);
    str[i + size--] = '\0';
    while (nbr > 0)
    {
        str[i + size--] = nbr % 10 + '0';
        nbr /= 10;
    }
    if (size == 0 && str[1] == '\0')
        str[i] = '0';
    else if (size == 0 && str[1] != '\0')
        str[i] = '-';
    return (str);  
}
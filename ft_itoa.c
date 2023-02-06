/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:33:36 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/06 15:11:48 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_size(int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
			n /= 10;
			size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	size_t	size;

	nbr = n;
	size = (ft_size(n) + ft_isneg(n));
	if (ft_isneg(n))
			nbr = nbr * -1;
	str = (char *)malloc((size + 1));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (nbr > 0)
	{
			str[size--] = ((nbr % 10) + '0');
			nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
			str[size] = '0';
	else if (size == 0 && str[1] != '\0')
			str[size] = '-';
	return (str);
}

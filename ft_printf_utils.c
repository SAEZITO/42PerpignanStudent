/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:23:33 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/23 16:54:22 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long ptr)
{
	char		*str;
	int		len;
	unsigned long	hexa;

	len = 1;
	hexa = ptr;
	while (hexa > 0)
	{
		hexa /= 16;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_putadress(ptr, str, len);
	free(str);
	return(len);
}

int	ft_print_nbr(int nbr)
{
	int	len;
	int	n;

	len = 1;
	n = nbr;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	ft_putnbr_fd(nbr, 1);
	return (len);
}

int	ft_print_usd(unsigned int nbr)
{
	int	len;
	int	n;

	len = 1;
	n = nbr;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	ft_putnbr_fd(nbr, 1);
	return (len);
}

int	ft_print_hex(unsigned int hex, char format)
{
	char	*str;
	unsigned int	nbr;
	int	len;

	nbr = hex;
	len = 1;
	while (nbr > 0)
	{
		nbr/=16;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (format == 'x')
		ft_puthexa(hex, str, len;
	else if (format == 'X')
		ft_putHEXA(hex, str, len);
	free(str);
	return(len);
}

int	ft_print_pct(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

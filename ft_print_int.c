/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:51:33 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/03 17:51:38 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_put_part_int(char *str_i, int d_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (d_i < 0 && flags.dot >= 0)
		ft_putchar_fd('-', 1);
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(str_i) - 1, 1);
	char_count += ft_putstrprec(str_i, ft_strlen(str_i));
	return (char_count);
}

static int	ft_put_part_int(char *str_i, int d_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(str_i, d_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str_i))
		flags.dot = ft_strlen(str_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(str_i), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(str_i, d_i, flags);
	return (char_count);
}

int	ft_treat_int(int i, t_flags flags)
{
	char	*str_i;
	int		d_i;
	int		char_count;

	d_i = i;
	char_count = 0;
	if (flags.dot == 0 && i == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putstrprec("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	str_i = ft_itoa(i);
	char_count += ft_put_part_int(str_i, d_i, flags);
	free(str_i);
	return (char_count);
}

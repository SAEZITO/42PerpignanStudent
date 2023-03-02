/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_csd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:40:31 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/02 19:44:40 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_treat_char(char c, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		ft_putchar_fd(c, 1);
	char_count = ft_treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar_fd(c, 1);
	return (char_count + 1);
}

static int	ft_in_put_part_int(char *d_i, int str_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (str_i < 0 && flags.dot >= 0)
		ft_putchar_fd('-', 1);
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(d_i) - 1, 1);
	char_count += ft_putstrprec(d_i, ft_strlen(d_i));
	return (char_count);
}

static int	ft_put_part_int(char *d_i, int str_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(d_i, str_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(d_i, str_i, flags);
	return (char_count);
}

int	ft_treat_int(int i, t_flags flags)
{
	char	*d_i;
	int		str_i;
	int		char_count;

	str_i = i;
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
	d_i = ft_itoa(i);
	char_count += ft_put_part_int(d_i, str_i, flags);
	free(d_i);
	return (char_count);
}
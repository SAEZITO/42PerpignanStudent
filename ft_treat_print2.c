/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_print2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:49:54 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/02 20:50:44 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_in_put_part_pointer(char *pointer, t_flags flags)
{
	int char_count;

	char_count = 0;
	char_count += ft_putstrprec("0x", 2);
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(pointer), 1);
		char_count += ft_putstrprec(pointer, flags.dot);
	}
	else
		char_count += ft_putstrprec(pointer, ft_strlen(pointer));
	return (char_count);
}

int	ft_treat_ptr(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		char_count;

	char_count = 0;
	if (ull == 0 && flags.dot == 0)
	{
		char_count += ft_putstrprec("0x", 2);
		return (char_count += ft_treat_width(flags.width, 0, 1));
	}
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		char_count += ft_in_put_part_pointer(pointer, flags);
	char_count += ft_treat_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_in_put_part_pointer(pointer, flags);
	free(pointer);
	return (char_count);
}

static int	ft_put_part_int(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(str), 0);
		char_count += ft_putstrprec(str, flags.dot);
	}
	else
	{
		char_count += ft_putstrprec(str, ft_strlen(str));
	}
	return (char_count);
}

int	ft_treat_string(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_put_part_int(str, flags);
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.width, flags.dot, 0);
	else
		char_count += ft_treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += ft_put_part_int(str, flags);
	return (char_count);
}

int	ft_putstrprec(char *str, int prec)
{
	int	char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
		ft_putchar_fd(str[char_count++], 1);
	return (char_count);
}

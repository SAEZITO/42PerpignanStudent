/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:49:10 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/02 20:49:43 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags	ft_flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int	ft_flag_dot(const char *str, int start,
			t_flags *flags, va_list args)
{
	int i;

	i = start;
	i++;
	if (str[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
			flags->dot = (flags->dot * 10) + (str[i++] - '0');
	}
	return (i);
}

int	ft_flag_parse(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_in_type_list(str[i])
			&& !ft_is_in_flags_list(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flag_dot(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (str[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit(str[i], *flags);
		if (ft_is_in_type_list(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}
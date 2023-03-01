/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:20:54 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/01 12:07:18 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.type = 0;
	flags.precision = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int		ft_treatment(int c, t_flags flags, va_list args)
{
	int char_count;

	char_count = 0;
	if (c == 'c')
		char_count = ft_print_char(va_arg(args, int), flags);
	else if (c == 's')
		char_count = ft_print_string(va_arg(args, char *), flags);
	else if (c == 'p')
		char_count = ft_print_ptr(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = ft_print_int(va_arg(args, int), flags);
	else if (c == 'u')
		char_count += ft_print_uint((unsigned int)va_arg(args, unsigned int),
		flags);
	else if (c == 'x' || c == 'X')
		char_count += ft_print_hexa(va_arg(args, unsigned int), c, flags);
	else if (c == '%')
		char_count += ft_print_percent(flags);
	return (char_count);
}

int			ft_flag_parse(const char *str, int i, t_flags *flags, va_list vars)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_in_type_list(str[i])
		&& !ft_is_in_flags_list(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flag_dot(str, i, flags, vars);
		if (str[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (str[i] == '#')
			*flags = ft_flag_width(vars, *flags);
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

int			ft_treat_str(const char *str, va_list vars)
{
	int			i;
	t_flags		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	flags = ft_init_flags();
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i = ft_flag_parse(str, ++i, &flags, vars);
			if (ft_is_in_type_list(str[i]))
				char_count += ft_treatment((char)flags.type, flags, vars);
			else if (str[i])
				char_count += ft_print_char(str[i]);
		}
		else if (str[i] != '%')
			char_count += ft_print_char(str[i]);
		i++;
	}
	return (char_count);
}

int			ft_printf(const char *input, ...)
{
	const char	*str;
	va_list		vars;
	int			char_count;

	str = ft_strdup(input);
	char_count = 0;
	va_start(vars, input);
	char_count += ft_treat_str(str, vars);
	va_end(vars);
	free((char *)str);
	return (char_count);
}

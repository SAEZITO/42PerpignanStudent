/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:31:07 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/28 20:24:37 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printform(char format, t_conv *conv, va_list vars)
{
	if (format == 'c')
	{
		conv->ret += 1;
		ft_putchar_fd(va_arg(vars, int), 1);
	}
	if (format == 's')
	{
		conv->ret += ft_strlen(va_arg(vars, char *));
		ft_putstr_fd(va_arg(vars, char *), 1);
	}
	if (format == 'p')
		conv->ret += ft_print_ptr(va_arg(vars, unsigned long));
	if (format == 'd' || format == 'i')
		conv->ret += ft_print_nbr(va_arg(vars, int));
	if (format == 'u')
		conv->ret += ft_print_nbr(va_arg(vars, unsigned int));
	if (format == 'x' || format == 'X')
		conv->ret += ft_print_hex(va_arg(vars, unsigned int), format);
	if (format == '%')
		conv->ret += ft_print_pct();
	return (conv->ret);
}

int	ft_parsing(char *str, int i, t_conv *conv)
{
	int	j;

	j = 0;
	while (str[i] && (ft_gettype("cspdiuxX", str[i], 0, 8) < 0))
	{
		if (str[i] == '0')
			conv->flag = str[i];
		if (str[i] <= '9' && str[i] > '0')
			conv->longueur = ft_atoi(&str[i]);
		if (str[i] == '-')
			conv->flag = str[i];
		if (str[i] == '.' && str[i + 1] <= '9' && str[i + 1] <= '0')
			conv->precision = ft_atoi(&str[i]);
		if ()

		if ()
	}
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	vars;
	t_conv	conv;
	int		i;	
	const char	*str;

	str = ft_strdup(input);
	i = 0;
	conv.ret = 0;
	va_start(vars, str);
	conv.vars = &vars;
	while (str[i] && i < ft_strlen(str))
	{
		while (str[i] != '%' && str[i])
		{
			ft_putchar_fd(str[i++], 1);
			conv.ret += 1;
		}
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar_fd(str[i], 1);
			i = i + 2;
			conv.ret += 1;
		}
		if (str[i] == '%' && str[i + 1] != '%' && str[i + 1])
			i = ft_parsing(str, i, &conv);
	}
	free((char *)str);
	return (conv.ret);
}

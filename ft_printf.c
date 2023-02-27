/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:31:07 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/27 12:02:55 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printform(va_list vars, const char format, int print_len)
{
	if (format == 'c')
	{
		print_len += 1;
		ft_putchar_fd(va_arg(vars, int), 1);
	}
	if (format == 's')
	{
		print_len += ft_strlen(va_arg(vars, char *));
		ft_putstr_fd(va_arg(vars, char *), 1);
	}
	if (format == 'p')
		print_len += ft_print_ptr(va_arg(vars, unsigned long));
	if (format == 'd')
		print_len += ft_print_nbr(va_arg(vars, int));
	if (format == 'u')
		print_len += ft_print_nbr(va_arg(vars, unsigned int));
	if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(vars, unsigned int), format);
	if (format == '%')
		print_len += ft_print_pct();
	return (print_len);
}

int		ft_parsing(char *str, int i, t_conv *conv)
{
	int j;

	conv->first = i;
	j = -1;
	while (((j = ft_gettype("cspdiuxX", str[i], 0, 8)) < 0) && str[i])
		i++;
	if (j < 0)
		conv->type = 'r';
	else
		conv->type = str[i];
	conv->end = i;
	conv->m = ft_largeur_memory(str, conv->first, i);
	ft_getlength(str, conv->first, i, conv);
	ft_getflag(str, conv);
	ft_getprecision(str, 0, conv, ft_precision_memory(str, conv));
	if (conv->type == 'd' || conv->type == 'i' || conv->type == 's'\
			|| conv->type == 'c')
		ft_impression(conv);
	else
		ft_impression2(conv, str);
	return (i + 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	vars;
	t_conv	conv;
	int		i;

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
		if (str[i] == '%' && str[i + 1] != '%')
			i = ft_parsing(str, i, &conv);
	}
	return (conv.ret);
}

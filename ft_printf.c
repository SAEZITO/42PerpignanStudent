/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:31:07 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/02 20:46:50 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//# include <stdio.h>

t_flags	ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int	ft_is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_is_in_flags_list(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int	ft_printment(int c, t_flags flags, va_list args)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		char_count = ft_putchar(va_arg(args, int), flags);
	else if (c == 's')
		char_count = ft_treat_string(va_arg(args, char *), flags);
	else if (c == 'p')
		char_count = ft_treat_ptr(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = ft_treat_int(va_arg(args, int), flags);
	else if (c == 'u')
		char_count += ft_treat_uint((unsigned int)va_arg(args, unsigned int),
				flags);
	else if (c == 'x')
		char_count += ft_treat_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += ft_treat_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		char_count += ft_treat_percent(flags);
	return (char_count);
}

int	ft_treat_str(const char *str, va_list args)
{
	int			i;
	t_flags		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!str[i])
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_flag_parse(str, ++i, &flags, args);
			if (ft_is_in_type_list(str[i]))
				char_count += ft_printment((char)flags.type, flags, args);
			else if (str[i])
				char_count += ft_putchar(str[i], flags);
		}
		else if (str[i] != '%')
			char_count += ft_putchar(str[i], flags);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	const char	*str;
	va_list		args;
	int			char_count;

	str = ft_strdup(input);
	char_count = 0;
	va_start(args, input);
	char_count += ft_treat_str(str, args);
	va_end(args);
	free((char *)str);
	return (char_count);
}

/*int	main(void)
{
	int	i;
	int	j;
	char	*str;
	char	c;
	int	res;

	c = '%';
	str = "bonjour";
	i = 100;
	j = 33;
	res = ft_printf("Start %% %010d %-.20i %p %c End \n", i, j, str, c);
	printf("Start %% %010d %-.20i %p %c End \n", i, j, str, c);
	ft_putnbr_fd(res, 1);
	return(0);
}*/

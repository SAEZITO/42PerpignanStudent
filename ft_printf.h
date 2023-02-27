/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:31:20 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/27 11:56:58 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

typedef struct		s_conv
{
	char			flag;
	int				largeur;
	int				precision;
	int				longueur;
	char			type;
	int				first;
	int				end;
	va_list			*vars;
	int				d;
	int				u2;
	char			*s;
	int				intc;
	char			c;
	void			*p;
	int				x;
	int				intx;
	int				ret;
	char			signe;
	unsigned long	adr;
}					t_conv;

int	ft_printform(va_list vars, const char format);
int	ft_print_ptr(unsigned long ptr);
int	ft_print_nbr(int nbr);

#endif

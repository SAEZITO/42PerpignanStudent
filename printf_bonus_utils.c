/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <alsaez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:31:01 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/28 21:25:19 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int		ft_is_in_type_list(int c)
{
    if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
            return (1);
	return (0);
}

int		ft_is_in_flags_list(int c)
{
    if ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '#') || (c == '+'))
        return (1);
	return (0);
}
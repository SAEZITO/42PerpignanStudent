/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:03:24 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/03 15:28:51 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_isdigit(int c)
{
	int	res;

	res = 0;
	if (c > 47 && c < 58)
		res = 1;
	return (res);
}

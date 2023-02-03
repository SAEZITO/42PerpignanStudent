/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:13:16 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/02 17:58:51 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		i = n - 1;
		while (i < n)
			((unsigned char *)dst)[i] = ((usigned char *)src)[i++];
	}
	else
	{
		while (i < n)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i++];
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:13:16 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/06 18:25:58 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	size_t	len;

	if (!dst && !src)
		return (NULL);
	len = ft_strlen(src);
	i = 0;
	if ((size_t)dst > (size_t)src)
	{
		while (len >= i)
		{
			len--;
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:33:36 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/07 16:41:38 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*dst;

	if (!nmemb)
		return (NULL);
	total = nmemb * size;
	dst = malloc(total);
	if (!dst || (nmemb != 0 && total / nmemb != size))
		return (NULL);
	ft_bzero(dst, nmemb * size);
	return (dst);
}

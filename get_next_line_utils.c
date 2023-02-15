/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:11:33 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/15 15:55:38 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	j;
	size_t	len;

	len = 0;
	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	len = -1;
	while (s1[++len])
		s[len] = s1[len];
	j = 0;
	while (s2[j])
		s[len++] = s2[j++];
	s[len] = '\0';
	return (s);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_getline(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_nextline(char *s)
{
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (0);
	i++;
	j = 0;
	while (s[i])
		s[j++] = s[i++];
	s[j] = '\0';
	return (s);
}

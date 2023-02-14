/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:11:33 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/14 18:15:54 by alsaez           ###   ########.fr       */
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
	char	*str;
	int		j;
	size_t	len;

	len = 0;
	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	len = -1;
	while (s1[++len])
		str[len] = s1[len];
	j = 0;
	while (s2[j])
		str[len++] = s2[j++];
	str[len] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!*s && !c)
		return ((char *)s);
	return (NULL);
}

char	*ft_getline(char *left_str)
{
	int		i;
	char	*s;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		s[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		s[i] = left_str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_nextline(char *left_str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		s[j++] = left_str[i++];
	s[j] = '\0';
	free(left_str);
	return (s);
}

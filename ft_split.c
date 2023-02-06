/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:42:05 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/06 17:55:28 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trig;

	i = 0;
	trig = 0;
	while (*str)
	{
		if (*str != c && trig == 0)
		{
			trig = 1;
			i++;
		}
		else if (*str == c)
			trig = 0;
		str++;
	}
	return (i);
}

static char	*word_cat(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(end - start + 1);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split || !s)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
				index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
				split[j++] = word_cat(s, index, i);
				index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

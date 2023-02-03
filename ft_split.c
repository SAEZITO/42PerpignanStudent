/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:42:05 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/03 16:00:59 by alsaez           ###   ########.fr       */
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
	int	i;

	i = 0;
	word = malloc((end - start + 1) * (char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		nbwords;
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	nbwords = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (nbwords + 1));
	if (!split)
		return (NULL);
	while (i < nbwords)
	{
		while (s[j] && s[j] == c)
			j++;
		k = j;
		while (s[k] && s[k] != c)
			k++;
		split[i++] = word_cat(s, j, k);
	}
split[i] = NULL;
return (split);
}



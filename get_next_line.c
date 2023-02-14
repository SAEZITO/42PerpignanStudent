/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:44 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/14 18:12:27 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_str(int fd, char *str)
{
	static char	*buff;
	int			read_b;

	buff = malloc(((BUFFER_SIZE) + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_b = 1;
	while (!ft_strchr(str, '\n') && read_b != 0)
	{
		read_b = read(fd, buff, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_b] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	str = ft_read_to_str(fd, str);
	line = ft_getline(str);
	str = ft_nextline(str);
	return (line);
}

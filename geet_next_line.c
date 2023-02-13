/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geet_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:44 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/13 16:05:40 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *line = NULL;
	static char *str = NULL;
	size_t ret;
	char buf[BUFFER_SIZE + 1];
	char *temp;
	
	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = 0;
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(str, '\n') == 1)
			break;
	}
	line = ft_select(str);
	temp = str;
	str = ft_select2(temp);
	free(temp);
	if (ft_check_return(ret, &str) == 0 && line[0] == '\0')
		return (NULL);
	return (line);
}

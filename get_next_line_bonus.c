/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:52:18 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/06/08 14:06:39 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_freetmp(char *tmp)
{
	free(tmp);
	return (NULL);
}

char	*ft_freeline(char *line, char *str)
{
	free(str);
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*tmp;
	char		*line;
	int			rd;

	if (fd < 0 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	rd = 1;
	while (!ft_strchr(str[fd], '\n') && rd > 0)
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd < 0)
			return (ft_freetmp(tmp));
		tmp[rd] = '\0';
		str[fd] = ft_strjoin(str[fd], tmp);
	}
	free(tmp);
	line = ft_joinline(str[fd]);
	str[fd] = ft_substr(str[fd], ft_len(str[fd], '\n') + 1, ft_len(str[fd], 0));
	if (!rd && *line == '\0')
		return (ft_freeline(line, str[fd]));
	return (line);
}

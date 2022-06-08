/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:52:18 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/06/08 13:42:34 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;
	char		*tmp;
	char		*line;
	int			rd;

	if (fd < 0 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	rd = 1;
	while (!ft_strchr(str, '\n') && rd > 0)
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd < 0)
			return (ft_freetmp(tmp));
		tmp[rd] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	line = ft_joinline(str);
	str = ft_substr(str, ft_len(str, '\n') + 1, ft_len(str, 0));
	if (!rd && *line == '\0')
		return (ft_freeline(line, str));
	return (line);
}

/* int	main(void)
{
	int		i;
	char	*result;
	int		fd;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 2)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
		i++;
	}
	close(fd);
} */

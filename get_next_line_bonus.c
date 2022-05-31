/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:52:18 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/05/31 19:13:59 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<limits.h>

char	*alloc_buf(void)
{
	char	*buff_read;

	buff_read = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buff_read)
		return (NULL);
	return (buff_read);
}

char	*join(int fd, char *buff_read, char *tmp)
{
	char	*aux_tmp;
	int		verification;

	verification = 1;
	while (verification)
	{
		verification = read (fd, buff_read, BUFFER_SIZE);
		if (verification <= 0 && tmp[0] == 0)
		{
			free(tmp);
			free(buff_read);
			return (NULL);
		}
		buff_read[verification] = '\0';
		aux_tmp = tmp;
		tmp = ft_strjoin(tmp, buff_read);
		if (!tmp)
			return (NULL);
		free(aux_tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	return (tmp);
}

char	*alloc_and_free(char *tmp, char *buff_read, int i)
{
	char	*line;

	line = ft_substr(tmp, 0, i + 1);
	free(tmp);
	free(buff_read);
	return (line);
}

void	ft_nospace(char **str, int fd)
{
	free(str[fd]);
	str[fd] = 0;
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buff_read;
	char		*tmp;
	int			i;

	if (fd < 0 || fd == 2)
		return (NULL);
	buff_read = alloc_buf();
	if (!buff_read)
		return (NULL);
	if (str[fd])
		tmp = str[fd];
	else
		tmp = ft_calloc(1, sizeof(char));
	tmp = join(fd, buff_read, tmp);
	if (!tmp || !buff_read)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	str[fd] = ft_substr(tmp, i + 1, -1);
	if (*str[fd] == '\0')
		ft_nospace(str, fd);
	return (alloc_and_free(tmp, buff_read, i));
}

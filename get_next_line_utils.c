/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:52:30 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/05/31 21:05:43 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
	{
		if (!s[i])
			break ;
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*result;
	int	i;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (start > ft_strlen(s))
	{
		*result = '\0';
		return (result);
	}
	while (len > 0 && start < ft_strlen(s))
	{
		result[i] = s[start];
		i++;
		start++;
		len--;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		lens1;

	lens1 = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		result[lens1] = s2[i];
		lens1++;
	}
	result[lens1] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	p = malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (p);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

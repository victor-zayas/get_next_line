/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:52:37 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/06/03 12:00:54 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_substr(char *str, int start, int len);
char	*ft_strjoin(char *str, char *tmp);
char	*ft_strchr(const char *s, int c);
int		ft_len(const char *str, char c);
char	*ft_joinline(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:52:37 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/05/31 21:05:42 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*join(int fd, char *buf_read, char *temp);
char	*alloc_and_free(char *temp, char *buf_read, int aux);
char	*alloc_buf(void);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int     ft_strlen(const char *str);

#endif

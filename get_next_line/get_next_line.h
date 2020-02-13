/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 09:37:19 by pserrano          #+#    #+#             */
/*   Updated: 2020/02/13 11:48:52 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
int			output(int fd, char **string, char **line, int ret);
int			save_line(char **string, char **line);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
char		*ft_strchr(char *s, int c);
int			ft_strlen(char *str);

#endif

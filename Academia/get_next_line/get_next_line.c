/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 10:29:23 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 10:05:56 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				save_line(char **string, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*string)[len] != '\0' && (*string)[len] != '\n')
		len++;
	if ((*string)[len] == '\n')
	{
		*line = ft_substr(*string, 0, len);
		temp = ft_strdup(&((*string)[len + 1]));
		free(*string);
		*string = temp;
	}
	else
	{
		*line = ft_strdup(*string);
		free(*string);
		*string = NULL;
		return (0);
	}
	return (1);
}

int				output(int fd, char **string, char **line, int ret)
{
	if (ret < 0)
	{
		free(string[fd]);
		return (-1);
	}
	else if (ret == 0 && string[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		return (save_line(&string[fd], line));
	}
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	static	char	*string[4096];
	char			*buffer;
	char			*line_temp;

	ret = 0;
	if (fd < 0 || line == 0 || BUFFER_SIZE == 0 ||
		!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (string[fd] == 0)
			string[fd] = ft_strdup(buffer);
		else
		{
			line_temp = ft_strjoin(string[fd], buffer);
			free(string[fd]);
			string[fd] = line_temp;
		}
		if (ft_strchr(string[fd], '\n'))
			break ;
	}
	free(buffer);
	return (output(fd, string, line, ret));
}

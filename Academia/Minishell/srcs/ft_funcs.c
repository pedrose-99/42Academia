/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:56:05 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/26 09:29:32 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

int	ft_dup(int fd)
{
	int	dup_fd;

	dup_fd = dup(fd);
	if (dup_fd < 0)
		exit(errno);
	return (dup_fd);
}

void	ft_dup2(int fd1, int fd2)
{
	int	value;

	value = dup2(fd1, fd2);
	if (value < 0)
		exit(errno);
}

void	ft_close(int fd)
{
	int	value;

	value = close(fd);
	if (value < 0)
		exit(errno);
}

void	*ft_malloc(int size)
{
	void	*allocate;

	allocate = malloc(size);
	if (!allocate)
		exit(19);
	return (allocate);
}

int	ft_open(char *file, int type)
{
	int	fd;

	fd = 0;
	if (type == 0)
	{
		fd = open(file, O_RDONLY, 0666);
		if (fd < 0)
		{
			ft_putstr_fd(file, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
	}
	else if (type == 1)
		fd = open(file,
				O_CREAT | O_TRUNC | O_WRONLY, 0666);
	else if (type == 2)
		fd = open(file,
				O_CREAT | O_APPEND | O_WRONLY, 0666);
	return (fd);
}

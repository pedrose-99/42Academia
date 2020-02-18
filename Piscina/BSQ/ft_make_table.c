/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:43:20 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/23 23:14:24 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		check_file(char *file)
{
	return (close(open(file, O_RDONLY)));
}

void	ft_open_dict(char *lib, char **buffer)
{
	int fd;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = open(lib, O_RDONLY);
	while (buffer[0][0] != '\n')
		read(fd, &buffer[0][0], 1);
	while (read(fd, &buffer[i][j], 1))
	{
		if (buffer[i][j] == '\n')
		{
			i++;
			j = -1;
		}
		j++;
	}
	close(fd);
}

void	ft_get_table(char *symbols, char **buffer, int **table_int, int row)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < row)
	{
		if (buffer[i][j] == symbols[1])
			table_int[i][j] = 1;
		else if (buffer[i][j] == symbols[2])
			table_int[i][j] = 0;
		if (buffer[i][j] == '\n')
		{
			i++;
			j = -1;
		}
		j++;
	}
}

char	**ft_char_table(int row, int column)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = (char**)malloc(sizeof(char*) * row);
	while (i < row)
	{
		ptr[i] = (char*)malloc(sizeof(char) * column);
		while (j < column)
		{
			ptr[i][j] = '0';
			j++;
		}
		ptr[i][j - 1] = '\n';
		j = 0;
		i++;
	}
	return (ptr);
}

int		**ft_int_table(int row, int column)
{
	int	**ptr;
	int	i;
	int j;

	i = 0;
	j = 0;
	ptr = (int**)malloc(sizeof(int*) * row);
	while (i < row)
	{
		ptr[i] = (int*)malloc(sizeof(int) * column);
		while (j < column)
		{
			ptr[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}
	return (ptr);
}

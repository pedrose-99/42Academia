/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:16:01 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/23 23:16:12 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


void	ft_part1(char *file, char symbols[4], char **buffer, int **table_int)
{
	if (symbols[0] == -1)
		write(2, "MAP_ERROR", 9);
	else
	{
		ft_part2(file, buffer, table_int);
		//ft_free_memory(buffer, table_int);
	}
}


void	ft_part2(char *file, char **buffer, int **table_int)
{
	int		array[2];
	int		size_square;
	int		square_pointer[2];
	char	symbols[4];

	array[0] = ft_get_number_of_lines(file);
	array[1] = ft_get_number_of_columns(file);
	buffer = ft_char_table(array[0], array[1]);
	ft_open_dict(file, buffer);
	table_int = ft_int_table(array[0], array[1]);
	ft_get_table(symbols, buffer, table_int, array[0]);
	size_square = ft_solve(table_int, square_pointer, array[0], array[1]);
	ft_fill_int_table(table_int, square_pointer, size_square);
	ft_write(symbols, buffer, table_int, array);
}

void	ft_free_memory(char **buffer, int **table)
{
	free(buffer);
	free(table);
}

int		main(int argc, char **argv)
{
	int		i;
	int		id;
	char	**buffer;
	int		**table_int;
	char	symbols[4];

	i = 1;
	while (i < argc)
	{
		id = open(argv[i], O_RDONLY);
		if (id == -1)
			write(2, "ERROR", 5);
		else
		{
			ft_handle_first_line(id, argv[i], symbols);
			ft_part1(argv[i], symbols, buffer, table_int);	
		}
		i++;
	}
	return (0);
}

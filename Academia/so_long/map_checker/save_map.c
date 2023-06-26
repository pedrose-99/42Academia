/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:29:06 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 15:35:57 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(char const *argv[])
{
	int		num_lines;
	int		fd;
	int		check_line;
	char	buffer;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (-1);
	num_lines = 1;
	while (1)
	{
		check_line = read(fd, &buffer, 1);
		if (check_line == 0)
			break ;
		if (check_line < 0)
			return (-1);
		if (buffer == '\n')
			num_lines++;
	}
	close(fd);
	return (num_lines);
}

char	**malloc_columns(int num_lines)
{
	char	**map;

	if (num_lines <= 1)
	{
		ft_printf("ERROR: NOT VALID FILE\n");
		return (NULL);
	}
	map = malloc(sizeof(char *) * num_lines + 1);
	if (!map)
	{
		ft_printf("ERROR: Malloc error\n");
		return (NULL);
	}
	return (map);
}

char	**initialize_map(char const *argv[])
{
	int		fd;
	int		num_lines;
	char	**new_map;
	int		i;
	char	*buffer;

	i = 0;
	buffer = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR: FILE NOT EXISTS\n");
		exit(1);
	}
	num_lines = count_lines(argv);
	new_map = malloc_columns(num_lines);
	if (!new_map)
		return (NULL);
	while (get_next_line(fd, &buffer))
		new_map[i++] = buffer;
	new_map[i++] = buffer;
	new_map[i] = NULL;
	close(fd);
	return (new_map);
}

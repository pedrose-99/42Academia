/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:26:03 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 14:32:03 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_info_intializor(t_info_map *map_info, char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j])
		j++;
	map_info->height = i;
	map_info->lenght = j;
	map_info->moves = 0;
}

int	check_map_init_and_end(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] == '1')
			j++;
		else
			return (0);
	}
	return (1);
}

int	check_map_body(char **map, int size_columns, int size_line)
{
	int	i;

	i = 1;
	while (i != size_columns)
	{
		if (map[i][0] != '1' || map[i][size_line] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(char **map, t_info_map *map_info)
{
	int		i;
	int		j;
	int		size_line;
	int		size_columns;

	i = 0;
	j = 0;
	size_columns = 0;
	while (map[size_columns])
		size_columns++;
	size_columns--;
	while (map[i][j])
		j++;
	size_line = j - 1;
	j = 0;
	if (!check_map_init_and_end(map, 0, 0) || !check_map_body(map, size_columns,
			size_line) || !check_map_init_and_end(map, size_columns, 0))
	{
		print_error_exit(UNBOUNDED_MAP, map_info);
		return (0);
	}
	return (1);
}

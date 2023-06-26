/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:30:17 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 15:36:34 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_objects(char **map, t_info_map map_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				map_info.objects++;
			else if (map[i][j] == 'E')
				map_info.exit++;
			else if (map[i][j] == 'P')
				map_info.init_poss++;
			j++;
		}
		i++;
	}
	if (map_info.objects >= 1 && map_info.exit == 1
		&& map_info.init_poss == 1)
		return (1);
	print_error_exit(MISSING_ITEMS, &map_info);
	return (0);
}

int	is_rectangle(char **map, t_info_map *map_info)
{
	int	aux;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
		j++;
	i++;
	aux = j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
		if (aux != j)
		{
			print_error_exit(NOT_RECTANGLE, map_info);
			return (0);
		}
	}
	return (1);
}

t_point	check_start(char **map, t_point begin)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				begin.x = i;
				begin.y = j;
				begin.lastx = i;
				begin.lasty = j;
			}
			i++;
		}
		j++;
	}
	return (begin);
}

int	get_coins(char **map)
{
	int	i;
	int	j;
	int	z;

	j = 0;
	z = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				z++;
			i++;
		}
		j++;
	}
	return (z);
}

int	initialize_and_check_map(char const *argv[], t_info_map *map_info)
{
	char		**map_aux;
	int			bad_exit;

	bad_exit = 1;
	map_aux = initialize_map(argv);
	if (!map_aux)
		return (0);
	map_info->map = initialize_map(argv);
	if (!map_aux)
		return (0);
	map_info_intializor(map_info, map_aux);
	map_file_is_correct((char *)argv[1], map_info);
	if (!is_rectangle(map_aux, map_info))
		bad_exit = 0;
	else if (!check_map(map_aux, map_info))
		bad_exit = 0;
	else if (!check_objects(map_aux, *map_info))
		bad_exit = 0;
	if (!check_laberinto(map_aux, map_info))
		bad_exit = 0;
	free_map(map_aux);
	if (!bad_exit)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:14:49 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 15:08:44 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	first_condition_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == 'E' || tab[cur.y][cur.x] == 'X')
	{
		if (tab[cur.y][cur.x] == 'E')
			tab[cur.y][cur.x] = 'X';
		return (0);
	}
	return (1);
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (first_condition_fill(tab, size, cur, to_fill) == 0)
		return ;
	if (tab[cur.y][cur.x] == '1')
		cur = wall_condition(cur, tab);
	else if (tab[cur.y][cur.x] == '0' || tab[cur.y][cur.x] == 'P'
		|| tab[cur.y][cur.x] == 'C')
		cur = condition_check_object(cur, tab);
	else if (tab[cur.y][cur.x] == 'R')
		cur = condicion_noexit(cur, tab);
	if (tab[cur.y][cur.x - 1] != 'F' && tab[cur.y][cur.x -1] != 'R'
		&& tab[cur.y][cur.x - 1] != 'W')
		fill(tab, size, (t_point){cur.x - 1, cur.y,
			cur.lastx, cur.lasty, cur.exit, cur.collect}, to_fill);
	if (tab[cur.y][cur.x + 1] != 'F' && tab[cur.y][cur.x +1] != 'R'
		&& tab[cur.y][cur.x + 1] != 'W')
		fill(tab, size, (t_point){cur.x + 1, cur.y, cur.lastx,
			cur.lasty, cur.exit, cur.collect}, to_fill);
	if (tab[cur.y - 1][cur.x] != 'F' && tab[cur.y - 1][cur.x] != 'R'
		&& tab[cur.y - 1][cur.x] != 'W')
		fill(tab, size, (t_point){cur.x, cur.y - 1, cur.lastx,
			cur.lasty, cur.exit, cur.collect}, to_fill);
	if (tab[cur.y + 1][cur.x] != 'F' && tab[cur.y + 1][cur.x] != 'R'
		&& tab[cur.y + 1][cur.x] != 'W')
		fill(tab, size, (t_point){cur.x, cur.y + 1, cur.lastx,
			cur.lasty, cur.exit, cur.collect}, to_fill);
}

t_point	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
	return (begin);
}

int	check_laberinto(char **map, t_info_map *map_info)
{
	t_point	begin;
	t_point	size;
	int		num_coins;
	int		i;

	i = 0;
	size.x = get_size_x(map);
	size.y = get_size_y(map);
	num_coins = get_coins(map);
	begin = check_start(map, begin);
	begin.collect = 0;
	begin.exit = 0;
	begin = flood_fill(map, size, begin);
	begin = check_components(map, size, begin);
	if (begin.collect != num_coins)
	{
		print_error_exit(COINS_CANT_COLLECT, map_info);
		return (0);
	}
	if (begin.exit != 1)
	{
		print_error_exit(NOT_REACH_EXIT, map_info);
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:34:15 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 17:51:49 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_take_item(t_info_map *map_info, int x, int y)
{
	if (map_info->map[map_info->pos_y][map_info->pos_x] == 'E')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.exit, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.grass, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = '0';
	}
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->images.grass, (map_info->pos_x + x) * 64,
		(map_info->pos_y + y) * 64);
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->images.hollow, (map_info->pos_x + x) * 64,
		(map_info->pos_y + y) * 64);
	map_info->pos_x = x + map_info->pos_x;
	map_info->pos_y = y + map_info->pos_y;
	map_info->objects--;
}

void	draw_character(t_info_map *map_info, int x, int y)
{
	if (map_info->map[map_info->pos_y][map_info->pos_x] == 'E')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.exit, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.grass, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = '0';
	}
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->images.grass, (map_info->pos_x + x) * 64,
		(map_info->pos_y + y) * 64);
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->images.hollow, (map_info->pos_x + x) * 64,
		(map_info->pos_y + y) * 64);
	map_info->pos_x = x + map_info->pos_x;
	map_info->pos_y = y + map_info->pos_y;
}

void	draw_exit(t_info_map *map_info, int x, int y)
{
	if (map_info->map[map_info->pos_y][map_info->pos_x] == 'E')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.exit, map_info->pos_x * 64,
			map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.grass, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = '0';
	}
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->images.exit, (map_info->pos_x + x) * 64,
		(map_info->pos_y + y) * 64);
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->images.waterhole, (map_info->pos_x + x) * 64,
		(map_info->pos_y + y) * 64);
	map_info->pos_x = x + map_info->pos_x;
	map_info->pos_y = y + map_info->pos_y;
	if (map_info->objects == 0)
		close_window(map_info);
}

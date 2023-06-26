/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:32:23 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 15:03:36 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_images(t_info_map *map_info)
{
	int	x;
	int	y;

	map_info->images.wall = mlx_xpm_file_to_image(map_info->mlx,
			"images/wall.xpm", &x, &y);
	map_info->images.hollow = mlx_xpm_file_to_image(map_info->mlx,
			"images/hollow.xpm", &x, &y);
	map_info->images.grass = mlx_xpm_file_to_image(map_info->mlx,
			"images/grass.xpm", &x, &y);
	map_info->images.exit = mlx_xpm_file_to_image(map_info->mlx,
			"images/waterhole.xpm", &x, &y);
	map_info->images.objects = mlx_xpm_file_to_image(map_info->mlx,
			"images/token.xpm", &x, &y);
	map_info->images.waterhole = mlx_xpm_file_to_image(map_info->mlx,
			"images/waterhole.xpm", &x, &y);
	if (map_info->images.wall && map_info->images.hollow
		&& map_info->images.grass
		&& map_info->images.exit && map_info->images.objects)
		return (1);
	return (0);
}

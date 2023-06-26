/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:42:51 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 16:18:32 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_map_images_conditional(t_info_map *map_info, int x, int y)
{
	if (map_info->map[y][x] == '1')
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.wall, x * 64, y * 64);
	else if (map_info->map[y][x] == 'P')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.hollow, x * 64, y * 64);
		map_info->pos_y = y;
		map_info->pos_x = x;
	}
	else if (map_info->map[y][x] == 'E')
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.exit, x * 64, y * 64);
	else if (map_info->map[y][x] == 'C')
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.objects, x * 64, y * 64);
	else if (map_info->map[y][x] == '0')
		mlx_put_image_to_window(map_info->mlx, map_info->window,
			map_info->images.grass, x * 64, y * 64);
}

void	create_map_images(t_info_map *map_info)
{
	int	i;
	int	j;

	j = 0;
	while (map_info->map[j])
	{
		i = 0;
		while (map_info->map[j][i] != '\0')
		{
			if (map_info->map[j][i] == 'C')
				map_info->objects++;
			create_map_images_conditional(map_info, i, j);
			i++;
		}
		j++;
	}
}

int	compare_last_char(char *file)
{
	int	i;
	int	ancla;

	while (file[i])
		i++;
	i--;
	if (file[i] == 'r')
		i--;
	else
		return (0);
	if (file[i] == 'e')
		i--;
	else
		return (0);
	if (file[i] == 'b')
		i--;
	else
		return (0);
	if (file[i] == '.')
		i--;
	else
		return (0);
	return (1);
}

void	map_file_is_correct(char *file, t_info_map *map_info)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5)
	{
		print_error_exit(NOT_VALID_MAP_FILE, map_info);
	}
	if (!compare_last_char(file))
	{
		print_error_exit(NOT_VALID_MAP_FILE, map_info);
	}
}

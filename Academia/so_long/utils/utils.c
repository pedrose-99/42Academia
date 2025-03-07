/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:39:58 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 09:52:40 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map_info(t_info_map *map_info)
{
	int	i;

	i = 0;
	while (map_info->map[i])
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map);
}

void	free_map(char **map)
{
	int	k;

	k = 0;
	while (map[k])
	{
		free(map[k]);
		k++;
	}
	free(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:50:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 15:21:14 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_missing_items(t_info_map *map_info)
{
	if (map_info->objects <= 0)
		ft_printf("ERROR: MISSING COINS\n");
	else if (map_info->exit <= 0)
		ft_printf("ERROR: MISSING EXIST\n");
	else if (map_info->exit > 1)
		ft_printf("ERROR: MORE THAN ONE EXIT\n");
	else if (map_info->init_poss <= 0)
		ft_printf("ERROR: MISSING INITIAL POSITION\n");
	else if (map_info->init_poss > 1)
		ft_printf("ERROR: MORE THAN ONE INITIAL POSITION\n");
}

void	print_other_errors(int error, t_info_map *map_info)
{
	if (error == COINS_CANT_COLLECT)
	{
		ft_printf("ERROR: CANT COLLECT ALL THE COINS\n");
		free_map_info(map_info);
		exit (1);
	}
	else if (error == NOT_REACH_EXIT)
	{
		ft_printf("ERROR: MAP HAS AN EXIT BUT WE CANT REACH IT\n");
		free_map_info(map_info);
		exit (1);
	}
	else if (error == NOT_RECTANGLE)
	{
		ft_printf("ERROR: NOT RECTANGLE\n");
		exit (1);
	}
	else if (error == MISSING_ITEMS)
	{
		check_missing_items(map_info);
		exit(1);
	}
}

//CAMBIAAAR
void	print_error_exit(int error, t_info_map *map_info)
{
	if (error == NOT_VALID_FORMAT)
	{
		ft_printf("ERROR: NOT A VALID MAP FORMAT\n");
		free_map_info(map_info);
		exit (1);
	}
	else if (error == IMAGES_NOT_FOUND)
	{
		ft_printf("ERROR: IMAGE OR IMAGES NOT FOUND\n");
		free_map_info(map_info);
		exit (1);
	}
	else if (error == NOT_VALID_MAP_FILE)
	{
		ft_printf("ERROR: NOT A VALID MAP FILE\n");
		exit (1);
	}
	else if (error == UNBOUNDED_MAP)
	{
		ft_printf("ERROR: UNBOUNDED MAP\n");
		exit (1);
	}
	else
		print_other_errors(error, map_info);
}

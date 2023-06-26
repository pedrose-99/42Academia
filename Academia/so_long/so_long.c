/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:38:43 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 11:15:20 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char const *argv[])
{
	t_info_map	map_info;

	if (argc != 2)
	{
		ft_printf("ERROR: Invalid arguments\n");
		return (0);
	}
	if (!initialize_and_check_map(argv, &map_info))
		;
	else
		map_render(&map_info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:35:51 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/20 11:37:20 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct  s_point
{
	int	x;
	int	y;
	int	lastx;
	int	lasty;
	int	collect;
	int	exit;
}	t_point;

typedef struct s_render_images
{
	void	*player;
	void	*wall;
	void	*grass;
	void	*objects;
	void	*exit;
	void	*player_goal;
}	t_render_images;

typedef struct s_info_map
{
	int					pos_x;
	int					pos_y;
	int					init_poss;
	int					objects;
	int					exit;
	char				**map;
	int					height;
	int					lenght;
	int					*mlx;
	int					*window;
	int					end_game;
	int					moves;
	t_render_images		images;

}	t_info_map;


int		is_rectangule(t_list *map);
int		save_map(t_list *map);
void	get_map(t_list **map, char const *argv[]);

#endif
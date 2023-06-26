/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maze_conditions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:16:13 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/21 15:28:22 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_condition(t_point cur, char **tab)
{
	if (tab[cur.y][cur.x -1] == 'R' || tab[cur.y][cur.x -1] == 'W')
	{
		cur.y = cur.y;
		cur.x = cur.x - 1;
	}
	else if (tab[cur.y][cur.x +1] == 'R' || tab[cur.y][cur.x + 1] == 'W')
	{
		cur.y = cur.y;
		cur.x = cur.x + 1;
	}
	else if (tab[cur.y - 1][cur.x] == 'R' || tab[cur.y - 1][cur.x] == 'W')
	{
		cur.y = cur.y - 1;
		cur.x = cur.x;
	}
	else if (tab[cur.y + 1][cur.x] == 'R' || tab[cur.y +1][cur.x] == 'W')
	{
		cur.y = cur.y + 1;
		cur.x = cur.x;
	}
	else
		return (0);
	return (1);
}

t_point	condicion_noexit(t_point cur, char **tab)
{
	if ((tab[cur.y][cur.x - 1] == 'F' || tab[cur.y][cur.x - 1] == 'R'
		|| tab[cur.y][cur.x -1] == 'W') && (tab[cur.y][cur.x + 1] == 'F'
		|| tab[cur.y][cur.x + 1] == 'R' || tab[cur.y][cur.x +1] == 'W')
		&& (tab[cur.y - 1][cur.x] == 'F' || tab[cur.y - 1][cur.x] == 'R'
		|| tab[cur.y - 1][cur.x] == 'W') && (tab[cur.y + 1][cur.x] == 'F'
		|| tab[cur.y + 1][cur.x] == 'R' || tab[cur.y + 1][cur.x] == 'W'))
	{
		tab[cur.y][cur.x] = 'F';
		if (!check_condition(cur, tab))
			exit(1);
		else
		{
			cur.lastx = cur.x;
			cur.lasty = cur.y;
		}
	}
	return (cur);
}

t_point	wall_condition(t_point cur, char **tab)
{
	tab[cur.y][cur.x] = 'F';
	cur.y = cur.lasty;
	cur.x = cur.lastx;
	return (cur);
}

t_point	condition_check_object(t_point cur, char **tab)
{
	if (tab[cur.y][cur.x] == 'C' || tab[cur.y][cur.x] == 'W')
		tab[cur.y][cur.x] = 'W';
	else
		tab[cur.y][cur.x] = 'R';
	cur.lastx = cur.x;
	cur.lasty = cur.y;
	return (cur);
}

t_point	check_components(char **area, t_point size, t_point begin)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < size.y)
	{
		i = 0;
		while (i <= size.x)
		{
			if (area[j][i] == 'W')
				begin.collect++;
			if (area[j][i] == 'X')
				begin.exit++;
			i++;
		}
		j++;
	}
	return (begin);
}

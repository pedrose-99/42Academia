/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_maze.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:56:20 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/20 09:56:22 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Esta funcion guarda el mapa con un malloc
char**	make_area(char** zone, t_point size)
{
	char	**new;

	new = malloc(sizeof(char *) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
	new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}
// Esta funcion comprueba si la siguiente posición esta libre o no 
int		check_condition(t_point cur, char **tab)
{
	if (tab[cur.y][cur.x -1] == 'R' || tab[cur.y][cur.x -1] == 'W')
	{
		cur.y = cur.y;
		cur.x = cur.x - 1;
	}
	else if (tab[cur.y][cur.x +1] == 'R' || tab[cur.y][cur.x+1] == 'W')
	{
		cur.y = cur.y;
		cur.x = cur.x + 1;
	}
	else if (tab[cur.y - 1][cur.x] == 'R' || tab[cur.y-1][cur.x] == 'W')
	{
		cur.y = cur.y - 1;
		cur.x = cur.x;
	}
	else if (tab[cur.y + 1][cur.x] == 'R' || tab[cur.y+1][cur.x] == 'W')
	{
		cur.y = cur.y + 1;
		cur.x = cur.x;
	}
	else
		return (0);
	return (1);
}

// Esta funcion usa se usa cuando no se puede avanzar
t_point		condicion_noexit(t_point cur, char **tab)
{
    if ((tab[cur.y][cur.x - 1] == 'F' || tab[cur.y][cur.x - 1] == 'R' || tab[cur.y][cur.x -1] == 'W') 
		&& (tab[cur.y][cur.x + 1] == 'F' || tab[cur.y][cur.x+1] == 'R' || tab[cur.y][cur.x +1] == 'W') 
		&& (tab[cur.y - 1][cur.x] == 'F' || tab[cur.y-1][cur.x] == 'R' || tab[cur.y-1][cur.x] == 'W') 
		&& (tab[cur.y + 1][cur.x] == 'F' || tab[cur.y+1][cur.x] == 'R' || tab[cur.y+1][cur.x] == 'W'))
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

// Esta función se usa cuando hay un muro
t_point	wall_condition(t_point cur, char **tab)
{
	tab[cur.y][cur.x] = 'F';
	cur.y = cur.lasty;
	cur.x = cur.lastx;
	return (cur);
}

// Esta funcion se usa cuando hay un objeto
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

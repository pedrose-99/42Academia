/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:55:10 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/20 09:55:19 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

// Esta función obtiene el tamaño horizontal del mapa
int	get_size_x(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

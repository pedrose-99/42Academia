/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:15:05 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/23 23:15:15 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write(char *symbols, char **table_char, int **table_int, int arr[2])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < arr[0])
	{
		while (j < arr[1])
		{
			if (table_int[i][j] > 0)
				table_char[i][j] = symbols[1];
			else if (table_int[i][j] == 0)
				table_char[i][j] = symbols[2];
			else if (table_int[i][j] == -1)
				table_char[i][j] = symbols[3];
			ft_putchar(table_char[i][j]);
			j++;
		}
		j = 0;
		write(1, "\n", 1);
		i++;
	}
}

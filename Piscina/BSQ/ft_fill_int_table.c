/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:13:39 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/23 23:13:48 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fill_int_table(int **table_int, int *square_pointer, int size_square)
{
	int i;
	int j;

	i = square_pointer[0] - size_square + 1;
	j = square_pointer[1] - size_square + 1;
	while (i <= square_pointer[0])
	{
		while (j <= square_pointer[1])
		{
			table_int[i][j] = -1;
			j++;
		}
		j = square_pointer[1] - size_square + 1;
		i++;
	}
}

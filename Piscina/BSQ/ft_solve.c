/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:14:45 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/23 23:14:54 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_min(int ptr1, int ptr2, int ptr3)
{
	int minimum;

	minimum = 0;
	if (ptr1 <= ptr2 && ptr1 <= ptr3)
		minimum = ptr1;
	if (ptr2 <= ptr1 && ptr2 <= ptr3)
		minimum = ptr2;
	if (ptr3 <= ptr1 && ptr3 <= ptr2)
		minimum = ptr3;
	return (minimum);
}

int		ft_new_max(int table_int, int *final_pointer, int i, int j)
{
	int new_max;

	new_max = table_int;
	final_pointer[0] = i;
	final_pointer[1] = j;
	return (new_max);
}

void	ft_check(int i, int j, int **table_int)
{
	if (i == 0 || j == 0)
		table_int[i][j] = 1;
	else
		table_int[i][j] = (ft_min(table_int[i - 1][j],
					table_int[i][j - 1],
					table_int[i - 1][j - 1]) + 1);
}

int		ft_solve(int **table_int, int *final_pointer, int row, int column)
{
	int i;
	int j;
	int size_square;

	size_square = 0;
	i = 0;
	j = 0;
	while (i < row)
	{
		while (j < column)
		{
			if (table_int[i][j] == 0)
				table_int[i][j] = 0;
			else
			{
				ft_check(i, j, table_int);
			}
			if (table_int[i][j] > size_square)
				size_square = ft_new_max(table_int[i][j], final_pointer, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (size_square);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:25:21 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/15 13:14:34 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_check_iguality_row(int **matrix)
{
	int		i;
	int		checking;

	checking = 1;
	i = -1;
	while (i++ <= 3)
	{
		if (matrix[i][0] == matrix[i][1] || matrix[i][0] == matrix[i][2])
			checking = 0;
		if (matrix[i][0] == matrix[i][3] || matrix[i][1] == matrix[i][2])
			checking = 0;
		if (matrix[i][1] == matrix[i][3] || matrix[i][2] == matrix[i][3])
			checking = 0;
		if (checking == 0)
			return (checking);
	}
	return (checking);
}

int	ft_check_iguality_col(int **matrix)
{
	int		j;
	int		checking;

	checking = 1;
	j = -1;
	while (j++ <= 3)
	{
		if (matrix[0][j] == matrix[1][j] || matrix[0][j] == matrix[2][j])
			checking = 0;
		if (matrix[0][j] == matrix[3][j] || matrix[1][j] == matrix[2][j])
			checking = 0;
		if (matrix[1][j] == matrix[3][j] || matrix[2][j] == matrix[3][j])
			checking = 0;
		if (checking == 0)
			return (checking);
	}
	return (checking);
}

int		ft_count_posibilities(int *array1, int *array2, int i)
{
	int		conta;

	conta = 0;
	if (array1[i] == 1 && array2[i] == 2)
		conta = 2;
	if (array1[i] == 1 && array2[i] == 3)
		conta = 3;
	if (array1[i] == 1 && array2[i] == 4)
		conta = 1;
	if (array1[i] == 2 && array2[i] == 1)
		conta = 2;
	if (array1[i] == 2 && array2[i] == 2)
		conta = 6;
	if (array1[i] == 2 && array2[i] == 3)
		conta = 3;
	if (array1[i] == 3 && array2[i] == 1)
		conta = 3;
	if (array1[i] == 3 && array2[i] == 2)
		conta = 3;
	if (array1[i] == 4 && array2[i] == 1)
		conta = 1;
	return (conta);
}

int		ft_check_vis_for_rc(int **matrix, char *option, int i, int a)
{
	int		j;
	int		checking;

	checking = 1;
	j = 0;
	if (a == 0)
	{
		while (j <= 3)
		{
			if (matrix[i][j] != option[j])
				checking = 0;
			j++;
		}
	}
	else
	{
		while (j <= 3)
		{
			if (matrix[j][i] != option[j])
				checking = 0;
			j++;
		}
	}
	return (checking);
}

int    ft_check_visibility_row(int **matrix, int *rowleft, int *rowright)
{
    int        checking;
    int        i;
    char        *option;
    int        conta;
    int        j;
    
    option = malloc(5);
    checking = 1;
    i = 0;
    j = 0;
    while (i <= 3)
    {
        conta = ft_count_posibilities(rowleft, rowright, i);
        while (j < conta)
        {
            *option = get_library(rowleft[i], rowright[i], j);
            checking = ft_check_vis_for_rc(matrix, option, i, 0);
            j++;
            free(option);
            if (checking == 0)
                return (checking);
        }
    }
    return (checking);
}

int    ft_check_visibility_col(int **matrix, int *colup, int *coldown)
{
    int        checking;
    int        i;
    char        *option;
    int        conta;
    int        j;
    
    option=malloc(5);
    checking = 1;
    i = 0;
    j = 0;
    while (i <= 3)
    {
        conta = ft_count_posibilities(colup, coldown, i);
        while (j < conta)
        {
            *option = get_library(colup[i], coldown[i], j);
            checking = ft_check_vis_for_rc(matrix, option, i, 1);
            j++;
            if (checking == 0)
                return (checking);
        }
    }
    return (checking);
}
void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int *ptr_aux;
	int cam;
	int *ult_direc;

	cam = 1;
	ult_direc = tab + size - 1;
	ptr_aux = tab;
	while (cam)
	{
		cam = 0;
		ptr_aux = tab;
		while (ptr_aux < ult_direc && !cam)
		{
			if (*(ptr_aux + 1) < *ptr_aux)
			{
				ft_swap(ptr_aux + 1, ptr_aux);
				cam = 1;
			}
			ptr_aux++;
		}
	}
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:11:16 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/12 18:09:55 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int col1up=3,col2up=2, col3up=1, col4up=2, row1right=2, row2right=1, row3right=3, row4right=3;
	int col1down=1, col2down=2, col3down=3, col4down=2, row1left=3, row2left=2, row3left=2, row4left=1;
	int matrix[4][4];
	int i=0, j=0;

	while(i<4)
	{
		while(j<4)
		{
			matrix[i][j]=0;
			printf("%d ", matrix[i][j]);
			j++;
		}
		j= 0;
		i++;
		printf("\n");
	}
	printf("\n\n");
	j = 0;
	i = 0;
	
	//voy a colocar los cuatros y los unos.

	//Estan colocados los 4's y los 1's
	//Ahora vamos contar los 4's y los 1's
	
	//Con los 4's y 1's contados, si hay tres se coloca el cuarto.
	
	i=0;
	j=0;
	while(i<4)
	{
		while(j<4)
		{	
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}

	return(0);
}

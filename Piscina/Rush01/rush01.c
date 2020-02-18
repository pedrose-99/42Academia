/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:11:16 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/15 13:14:06 by pserrano         ###   ########.fr       */
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
	if(col1up == 4)
	{
	matrix[0][0]=1;
		matrix[1][0]=2;
		matrix[2][0]=3;
		matrix[3][0]=4;
	}
	else if(col1up==1)
		matrix[0][0]=4;
	//col1up

	if(col2up==4)
	{
		matrix[0][1]=1;
		matrix[1][1]=2;
		matrix[2][1]=3;
		matrix[3][1]=4;
	}
	else if(col2up==1)
		matrix[0][1]=4;
	//col2up

	if(col3up==4)
	{
		matrix[0][2]=1;
		matrix[1][2]=2;
		matrix[2][2]=3;
		matrix[3][2]=4;
	}
	else if(col3up==1)
		matrix[0][2]=4;
	//col3up

	if(col4up==4)
	{
		matrix[0][3]=1;
		matrix[1][3]=2;
		matrix[2][3]=3;
		matrix[3][3]=4;
	}
	else if(col4up==1)
		matrix[0][3]=4;
	//col4up



	if(col1down==4)
	{
		matrix[3][0]=1;
		matrix[2][0]=2;
		matrix[1][0]=3;
		matrix[0][0]=4;
	}
	else if(col1down==1)
		matrix[3][0]=4;
	//col1down

	if(col2down==4)
	{
		matrix[3][1]=1;
		matrix[2][1]=2;
		matrix[1][1]=3;
		matrix[0][1]=4;
	}
	else if(col2down==1)
		matrix[3][1]=4;
	//col2dow2

	if(col3down==4)
	{
		matrix[3][2]=1;
		matrix[2][2]=2;
		matrix[1][2]=3;
		matrix[0][2]=4;
	}
	else if(col3down==1)
		matrix[3][2]=4;
	//col3down

	if(col4down==4)
	{
		matrix[3][3]=1;
		matrix[2][3]=2;
		matrix[1][3]=3;
		matrix[0][3]=4;
	}
	else if(col4down==1)
		matrix[3][3]=4;
	//col4down



	if(row1left==4)
	{
		matrix[0][0]=1;
		matrix[0][1]=2;
		matrix[0][2]=3;
		matrix[0][3]=4;
	}
	else  if(row1left==1)
		matrix[0][0]=4;
	//row1left

	if(row2left==4)
	{
		matrix[1][0]=1;
		matrix[1][1]=2;
		matrix[1][2]=3;
		matrix[1][3]=4;
	}
	else if (row2left==1)
		matrix[1][0]=4;
	//row2left

	if(row3left==4)
	{
		matrix[2][0]=1;
		matrix[2][1]=2;
		matrix[2][2]=3;
		matrix[2][3]=4;
	}
	else if(row3left==1)
		matrix[2][0]=4;
	//row3left

	if(row4left==4)
	{
		matrix[3][0]=1;
		matrix[3][1]=2;
		matrix[3][2]=3;
		matrix[3][3]=4;
	}
	else if(row4left==1)
		matrix[3][0]=4;
	//row4left


	if(row1right==4)
	{
		matrix[0][3]=1;
		matrix[0][2]=2;
		matrix[0][1]=3;
		matrix[0][0]=4;
	}
	else if(row1right==1)
		matrix[0][3]=4;
	//row1right

	if(row2right==4)
	{
		matrix[1][3]=1;
		matrix[1][2]=2;
		matrix[1][1]=3;
		matrix[1][0]=4;
	}
	else if(row2right==1)
		matrix[1][3]=4;
	//row2right

	if(row3right==4)
	{
		matrix[2][3]=1;
		matrix[2][2]=2;
		matrix[2][1]=3;
		matrix[2][0]=4;
	}
	else if(row3right==1)
		matrix[2][3]=4;
	//row3right

	if(row4right==4)
	{
		matrix[3][3]=1;
		matrix[3][2]=2;
		matrix[3][1]=3;
		matrix[3][0]=4;
	}
	else if(row4right==1)
		matrix[3][3]=4;
	//row4right

	//Estan colocados los 4's y los 1's
	//Si hay un 1, se llena la fila
	//Ahora vamos contar los 4's y los 1's
	i=0;
	j=0;
	int conta4=0;
	int conta1=0;
	while(i<4)
	{
		while(j<4)
		{
			if (matrix[i][j]==4)
				conta4++;
			if (matrix[i][j]==1)
				conta1++;
			j++;
		}
		j=0;
		i++;
	}
	printf("El numero de 4's es %d\n",conta4);
	printf("El numero de 1's es %d\n", conta1);
	printf("\n\n");

	//Con los 4's y 1's contados, si hay tres se coloca el cuarto.
	
	if(conta4==3)
	{	int array4[2];
		i=0;
		j =0;
		while(i<4)
		{
			if(matrix[i][j]!=4 && matrix[i][j+1]!=4 && matrix[i][j+2]!=4 && matrix[i][j+3]!=4 )
				array4[0]=i;
			 // en la posicion 0 del array esta guardado el numero de fila en la que falta el cuatro.
			i++;
		}
		printf("En la fila %d no hay cuatros.\n", array4[0]);

		i=0;j=0;
		while(j<4)
		{
				if(matrix[i][j]!=4 && matrix[i+1][j]!=4 && matrix[i+2][j]!=4 && matrix[i+3][j]!=4)
					array4[1]=j;
				// en la posicion 1 del array esta guardado el numero de columna donde no hay cuatros.
			j++;
		}

		printf("En la columna %d no hay  cuatros\n", array4[1]);
		i=array4[0];
		j=array4[1];
		matrix[i][j]=4;
		//Ahora ya tenemos los cuatro 4's
		//Si hay un uno, escribir a partir de el 1 2 3 4
	}

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

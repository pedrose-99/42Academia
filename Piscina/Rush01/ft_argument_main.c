/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:15:41 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/15 13:14:59 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**create_frame(char *string_arg);
//int B_T(int **,int **,int);
int ft_check_iguality_row(int **);
int ft_check_iguality_col(int **);
int ft_count_posibilities(int *, int *, int);
int ft_check_vis_for_rc(int **, char *, int,int);
int ft_check_visibility_row(int **, int *, int *);
int ft_check_visibility_col(int **, int *, int *);
void ft_swap(int *, int *);
void ft_sort_in_tab(int *, int);


int	main(int argc, char **argv)
{
	char	**frame;
	(void)argc;
	(void)argv;
	//int *result;
	//int *end=0;
	frame = create_frame(argv[1]);
	result=0;
	//B_T(matrix,solution,result,end);
}


void	bucl(char **frame, char *string_arg)
{
	int 	position;
	int 	count;
	int		var;
	
	position = 0;
	count = 0;
	var = 0;
	while (*string_arg)
	{
		if (position  % 2 == 0)
		{
			frame[count][var] = *string_arg;
			var++;
		}
		if (var == 4)
			var = 0;
		count++;
		string_arg++;
		position++;
	}
}

char	**create_frame(char *string_arg)
{
	char	**frame = malloc(20);

	frame[0] = malloc(5);
	frame[1] = malloc(5);
	frame[2] = malloc(5);
	frame[3] = malloc(5);
	bucl(frame,  string_arg);
	return(frame);
}

int B_T(int **matrix,int **solution, int *result,int *end)
{
	resut = ft_check_iguality_row(matrix);
	if(result == 1)
	{
		result = check_iguality_colum(matrix);
		if(result == 1)
		{
			result=ft_check_visibility_row(matrix, rowleft, rowright);
			if(result == 1)
			{
				result=ft_check_visibility_row(matrix, colup, coldown);
				if(result == 1)
				{
					end = 1;
					//print solution
				}
			}
		}
	}
	else 
	{
		while(end == 0)
		{
			//matrix=solution
			//solution = solition+1
			//B_T(matrix,solution,result,end)
			if(end==1)
				return(0);

		}
	}


 
}


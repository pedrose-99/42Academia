/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:03:29 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/13 16:14:31 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *get_library(int x ,int y ,int z)
{
	char *library[5][5][6];

	library[1][2][0]="4123";
	library[1][2][1]="4213";
	library[1][3][0]="4132";
	library[1][3][1]="4231";
	library[1][3][2]="4312";
	library[1][4][0]="4321";
	library[2][1][0]="3124";
	library[2][1][1]="3214";
	library[2][2][0]="1423";
	library[2][2][1]="2143";
	library[2][2][2]="2413";
	library[2][2][3]="3142";
	library[2][2][4]="3241";
	library[2][2][5]="3412";
	library[2][3][0]="1432";
	library[2][3][1]="2431";
	library[2][3][2]="3421";
	library[3][1][0]="1324";
	library[3][1][1]="2134";
	library[3][1][2]="2314";
	library[3][2][0]="1243";
	library[3][2][1]="1342";
	library[3][2][2]="2341";
	library[4][1][0]="1234";
	return (library[x][y][z]);
}

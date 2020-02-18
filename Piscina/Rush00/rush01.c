/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:13:35 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/05 18:40:10 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
int	rush (int x, int y)
{
	int X;
	int Y;

	X = 0;
	Y = 2;
		
	ft_first_line(x , y);
		while( Y <= y)
		{
			ft_body(x, y);
			Y++;
		}
	ft_last_line(x, y);

}
int	ft_first_line(int x , int y)
{
	int X;

	X = 0;

	while(x > 0 && y > 0 && X <= x )
	{
		if( X == 0)
		{
			ft_putchar('/');
			X++;
		}else if (X < x)
			{
				ft_putchar('*');
				X++;
			}else if (X == x)
				{
					ft_putchar('\\');
					ft_putchar('\n');
					X++;

				}
		}

}
int	ft_body(int x , int y)
{
	int X;

	X = 0;

	while(x > 0 && y > 0 && X <= x )
	{
		if( X == 0 or X == x){
			ft_putchar('*');
			X++;
			}else if (X == x)
				{
					ft_putchar(' ');
					X++;
				}

}

int	ft_last_line(int x , int y)
{
	int X;

	X = 0;

	while( x > 0 && y > 0 && X <= x )
	{
		if( X == x){
			ft_putchar('\\');
			X++;
		}else if (X < x)
			{
				ft_putchar('*');

				X++;
			}else if (X == x)
				{
					ft_putchar('/');
					X++;
				}
		}

}



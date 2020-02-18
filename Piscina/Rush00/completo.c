#include <stdio.h>
#include <unistd.h>


void	ft_putchar(char r)
{
	write(1, &r, 1);
}

void	ft_first_line(int x )
{
	int i;

	i = 1;

	while( i <= x )
	{
		if( i == 1)
		{
			ft_putchar('/');
			i++;
		}
		else if (i < x)
			{
				ft_putchar('*');
				i++;
			}
		else if (i == x)
				{
					ft_putchar('\\');
					i++;
					
				}
		}
		ft_putchar('\n');
}

void	ft_body(int x )
{
	int i;

	i = 1;	
	while( i <= x )
	{
		if( i == 1 )
		{
			ft_putchar('*');
			i++;
		}
			else if (i <  x)
				{
					ft_putchar(' ');
					i++;
				}
					else if( i == x)
					{
						ft_putchar('*');
						i++;
					}
		}
}

void	ft_last_line(int x , int y)
{
	int i;

	i = 1;

	while(i <= x && y != 1)
	{
		if( i == 1)
		{
			ft_putchar('\\');
			i++;
		}
			else if (i	< x)
			{
				ft_putchar('*');

				i++;
			}
				else if (i == x )
				{
					ft_putchar('/');
					i++;
					//ft_putchar('\n');
				}
		}
			if ( !(y==1))
			{
			ft_putchar('\n');
		}
}

int	rush (int x, int y)
{
	int j;

	j = 2;
	if(!( x==0 || y ==0)) 
	{
	ft_first_line(x );
	//ft_putchar('\n');
		while( j < y)
		{
			ft_body(x);
			j++;
			ft_putchar('\n');
		}
			ft_last_line(x, y);
	}
	return(0);
}


int	main(void)
{
	rush(5, 2);
	return(0);
}

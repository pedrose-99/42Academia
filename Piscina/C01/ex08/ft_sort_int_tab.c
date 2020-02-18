/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:41:15 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/11 07:29:13 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

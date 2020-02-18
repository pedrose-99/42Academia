/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:47:16 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/11 08:03:35 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		*ult_pos_cop;
	int		array_copia[size];
	int		*ptr_aux;
	int		n;

	n = 0;
	ult_pos_cop = array_copia + size - 1;
	ptr_aux = tab;
	while (n < size)
	{
		array_copia[n] = *ptr_aux;
		ptr_aux++;
		n++;
	}
	while (n > 0)
	{
		*tab = *ult_pos_cop;
		ult_pos_cop--;
		tab++;
		n--;
	}
}

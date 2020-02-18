/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:41:05 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/24 02:08:20 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb == 0 || nb == 1)
		return (0);
	while (i < nb)
	{
		if (nb / i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	nb++;
	while (!ft_find_next_prime(nb))
	{
		nb++;
	}
	return (nb);
}

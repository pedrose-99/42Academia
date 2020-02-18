/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:53:32 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/13 13:10:26 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *aux;
	t_list *aux2;

	aux = *lst;
	aux2 = NULL;
	while (aux)
	{
		aux2 = aux->next;
		del(aux->content);
		free(aux);
		aux = aux2;
	}
	*lst = 0;
}

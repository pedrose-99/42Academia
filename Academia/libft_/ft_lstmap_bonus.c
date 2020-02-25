/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:19:58 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/13 13:24:03 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *aux;

	if (!lst)
		return (NULL);
	aux = ft_lstnew(f(lst->content));
	new = aux;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(aux->next = ft_lstnew(f(lst->content))))
		{
			del(aux->next);
			free(aux->next);
			return (NULL);
		}
		aux = aux->next;
	}
	return (new);
}

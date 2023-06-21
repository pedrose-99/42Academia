/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:23:41 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/13 11:49:55 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list *new_element;

	if (!(new_element = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_element->content = (void*)content;
	new_element->next = NULL;
	return (new_element);
}

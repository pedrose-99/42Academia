/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:20:55 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:20:56 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LINE = string to which characters will be removed.
**
** INDEX = Marks where in *line the characters will be removed.
**
** length = how many characters will be removed.
**
** Inserts length characters of addendum in the string line, creating a new one.
** Returns an index pointing to the character after the inserted bit.
** Removes length characters of the string line, creating a new one.
** Returns an index pointing to the character after the removed bit.
**
** NOTE:
** *line is assumed to be malloced.
*/

int	ft_extract(char **line, unsigned int index, unsigned int length)
{
	char	*aux;
	int		i;

	aux = malloc(ft_strlen(*line) - length + 1);
	if (!aux)
		return (0);
	if (length < index + 1)
		i = index + 1 - length;
	else
		i = 0;
	ft_strlcpy(aux, *line, i + 1);
	ft_strlcpy(&aux[i], &(*line)[index + 1], ft_strlen(&(*line)[index]));
	free(*line);
	*line = aux;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:35:30 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/16 11:57:57 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlenght(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	char			*ptr1;
	char			*ptr2;
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = ft_strlenght(dest);
	len_src = ft_strlenght(src);
	ptr1 = dest;
	ptr2 = src;
	i = 0;
	while (*ptr1)
		ptr1++;
	while (*ptr2 && len_src < size - 1)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		i++;
	}
	*ptr1 = '\0';
	if (len_src > size)
		len_src = size;
	return (len_dest + len_src);
}

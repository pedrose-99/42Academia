/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2020/02/25 07:58:21 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		ft_printf(const char *cosa, ...)
{
    va_list args;
    int cnt;
    int i;
    
    cnt = ft_strlen(cosa);
}

int        ft_strlen(char *str)
{
    int size;
    
    size = 0;
    while (str[size])
        size++;
    return (size);
}

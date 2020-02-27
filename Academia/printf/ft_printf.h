/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:54:27 by pserrano          #+#    #+#             */
/*   Updated: 2020/02/27 11:26:29 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct		s_list
{
	va_list		ap;
	int			cont; //contar el numero de "letras"
	int			pos; //posicion del string
	int			flag; //el tipo de letra que sea(s, d, u)
	int			numdespec; // numero de specifires tengamos (ej: "%05d" tendriamos 3)
	int		width; 
	int		precision; // para la precision
	char		*str;
}					t_list;
#endif
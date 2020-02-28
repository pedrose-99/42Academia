/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:54:27 by pserrano          #+#    #+#             */
/*   Updated: 2020/02/28 09:56:14 by pserrano         ###   ########.fr       */
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
	//char		*cosa; //para almacenar el string
	va_list		ap;

	int			cont; //contar el numero de "letras"
	int			pos; //posicion del string

	int			spec; //el tipo de letra que sea(s, d, u)

	int			space; //' '
	int			zero; 
	int			minus; //'-'
	int			width; //ancho 0 10000
	int			numspaces; // numero de specifires tengamos (ej: "%05d" tendriamos 3)
	int			precision; // para la precision
	int			precisionfl; // para saber el numero al que hay que redondear
	int			len; // tamaño del string/num
}					t_list;
#endif
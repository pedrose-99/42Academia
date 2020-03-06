/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:54:27 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/05 11:38:29 by pserrano         ###   ########.fr       */
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

	char		spec; //el tipo de letra que sea(s, d, u)

	int			zero; 
	int			minus; //'-'
	int			width; //ancho 0 10000
	int			precision; // para la precision
	int			len; // tamaño del string/num?
}					t_list;
#endif
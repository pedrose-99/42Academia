/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:54:27 by pserrano          #+#    #+#             */
/*   Updated: 2020/04/08 20:52:58 by pedro            ###   ########.fr       */
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
}					t_list;
int			ft_strlen(char *str);
int			ft_count_nb(long int nb);
void		ft_putnum(char *s, long int n, long int l);
char		*ft_itoa(long int n);
int			ft_is_space(char str);
int			ft_is_num(char str);
int			ft_atoi(const char *str);
void		ft_putchar(char c, t_list *f);
char		*print_menos(int num, char *p, t_list *f);
void		print_zero(int	tam, t_list *f);
void		print_space(int	tam, t_list *f);
void		print_cosita(char *p, t_list *f);
void 		init_struct(t_list *f);
int 		is_specifier(char c);
char 		*ft_store_data(char *cosa, t_list *f);
void		ft_store_data_def(t_list *f);
void		case_zero_o_prec(int i, char *p, int tam_num, t_list *f);
void		case_zero_prec(int tam_num, char *p, t_list *f);
void		case_minus_prec(int i, int tam_num, char *p, t_list *f);
void		case_width_prec(int i, int tam_num, char*p, t_list *f);
void		print_int(t_list *f);
void		caseu_zero_o_prec(char *p, int tam_num, t_list *f);
void		caseu_zero_prec(char *p, int tam_num, t_list *f);
void		caseu_minus_prec(char *p, int i, int tam_num, t_list *f);
void		caseu_width_prec(int i, int tam_num, char *p, t_list *f);
void		print_unsigned(t_list *f);
void		caseh_zero_o_prec(char *p, int tam_num, t_list *f);
void		caseh_zero_prec(char *p, int tam_num, t_list *f);
void		caseh_minus_prec(char *p, int i, int tam_num, t_list *f);
void		caseh_width_prec(char *p, int i, int tam_num, t_list *f);
char	 	*trans_hex(long int i, char c);
void		print_hexa(t_list *f);
char		*type_p(char *def);
char	 	*trans_hexp(long long int i);
void		print_hexap(t_list *f);
void		print_char(t_list *f);
void		print_string(char *i, int tam_str, t_list *f);
void		minus_precs(int tam_str, char *i, t_list *f);
void		zero_precs(int tam_str, char *i, t_list *f);
void		print_str(t_list *f);
void		print_todos(t_list *f);
int 		ft_printf(const char *cosa, ...);

#endif
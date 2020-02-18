/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:15:38 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/23 23:15:52 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	ft_check(int i, int j, int **table_int);
char	**ft_create_char_table(int dim1, int dim2);
void	ft_write(char *symbols, char **table_char, int **table_int, int arr[2]);
void	ft_putchar(char c);
int		check_file(char *file);
void	ft_open_dict(char *lib, char **buffer);
void	ft_get_table(char *symbols, char **buffer, int **table_int, int row);
char	**ft_char_table(int row, int column);
int		**ft_int_table(int row, int column);
int		ft_solve(int **table_int, int *final_pointer, int row, int column);
int		ft_new_max(int table_int, int size_square, int *final_pointer);
int		ft_min(int ptr1, int ptr2, int ptr3);
void	reset_file_read(int id, char *file);
int		get_line_lenght(int id, char *file, int i);
void	set_to_line(int id, char *file, int i);
void	ft_handle_first_line(int id, char *file, char *symbols);
int		ft_atoi(int size, int id, char *first_line);
int		power_ten(int exp);
int		handle_reminder(int id, char *file, int number_of_rows, char *symbols);
int		ft_get_number_of_columns(char *file);
int		ft_atoi(int size, int id, char *first_line);
int		ft_get_number_of_lines(char *files);
void	ft_fill_int_table(int **table_int, int *square_pointer,
		int size_square);
void	ft_part1(char *file, char symbols[4], char **buffer, int **table_int);
void	ft_part2(char *file, char**buffer, int **table_int);
void	ft_free_memory(char **buffer, int **table_int);
#endif

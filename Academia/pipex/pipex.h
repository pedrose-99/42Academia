/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:09:40 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/10 17:36:22 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

void	free_arr(char ***arr);
int		get_path(char *cmd, char *envp[], char **f_path, int i);
void	free_matrix(char **matrix);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_access(char *path);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_strcat(char *s1, const char *s2);
void	ft_strdel(char **as);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s1);
char	*search_path(char **paths, char *cmd);
char	*ft_strtoupper(char *str);
char	*ft_strcpy(char *s1, const char *s2);
char	**str_split (char *str, char sep);
int		str_ichr (char *str, char c);
void	ft_putendl_fd(char const *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
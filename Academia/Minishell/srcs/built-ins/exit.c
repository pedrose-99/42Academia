/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:23:12 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/26 09:35:07 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h" 
#include "../../libft/libft.h"

static int	exit_error_cases(char **cmd, t_mshell *mshell)
{
	if (matrix_len(cmd) > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		mshell->data.last_cmd = 1;
		mshell->data.last_err = 1;
		errno = 1;
		return (1);
	}
	else if (cmd[1] && ft_str_is_digit(cmd[1]) == 0)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		mshell->data.last_cmd = 255;
		mshell->data.last_err = 255;
		errno = 255;
		return (2);
	}
	return (0);
}

void	b_exit(char **cmd, t_mshell *mshell)
{
	long long int	value;

	value = 0;
	if (exit_error_cases(cmd, mshell) > 0)
		return ;
	if (cmd[1])
		exit(value);
	exit(errno);
}

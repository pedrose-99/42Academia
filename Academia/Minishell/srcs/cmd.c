/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:47:29 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/26 09:25:01 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

void	cmd_op(t_list **tokens, t_mshell *mshell)
{
	t_list	*curr;

	check_sustitution(*tokens, mshell);
	curr = *tokens;
	if (check_var_assignment(&curr, mshell) == 0)
	{
		if (set_redirections(*tokens, mshell) == 1)
			search_cmd(mshell, curr);
	}
	after_execute_cmd(mshell);
}

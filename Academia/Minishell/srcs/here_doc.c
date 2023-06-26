/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:31:39 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/26 09:31:21 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

static void	write_here_doc(char *lim, char *name, t_mshell *mshell)
{
	char	*line;
	int		fd;

	fd = open(name, O_CREAT | O_RDWR | O_APPEND | O_TRUNC, 0666);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = readline("pipe heredoc> ");
	while (ft_strncmp(line, lim, longer_str(line, lim)) != 0)
	{
		if (ft_strchr(line, '$'))
			line = dollar_expansion(line, mshell);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline("pipe heredoc> ");
		if (!*line)
			break ;
	}
	free(line);
	close(fd);
	exit(EXIT_SUCCESS);
}

static char	*here_doc(char *lim, t_mshell *mshell)
{
	char	*name;
	char	*str_num;
	int		pid;
	int		wstatus;

	str_num = ft_itoa(mshell->data.here_docs);
	name = ft_strjoin("here_doc", str_num);
	free(str_num);
	pid = fork();
	if (pid == 0)
	{
		signals_child();
		write_here_doc(lim, name, mshell);
	}
	signals_parent_wait();
	waitpid(pid, &wstatus, 0);
	signals_parent();
	cmd_return(mshell, wstatus);
	if (mshell->data.last_cmd != 0)
	{
		free(name);
		mshell->data.here_doc_success = 0;
		return (NULL);
	}
	return (name);
}

void	here_doc_initializer(t_btree *root, t_mshell *mshell)
{	
	t_list		*tokens;
	char		*file;

	if (!root || mshell->data.here_doc_success == 0)
		return ;
	tokens = (t_list *)root->content;
	while (tokens)
	{
		if (get_token(tokens)->type == HERE_DOC)
		{
			mshell->data.here_docs++;
			file = here_doc(get_file_name(tokens->next), mshell);
			if (file)
				ft_lstadd_back(&(mshell->data.here_doc), ft_lstnew(file));
			else
				return ;
		}
		tokens = tokens->next;
	}
	here_doc_initializer(root->left, mshell);
	here_doc_initializer(root->right, mshell);
}

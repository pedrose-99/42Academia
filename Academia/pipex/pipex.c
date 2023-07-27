/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:24:00 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/10 16:41:01 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "pipex.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int	openfile(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, filename, str_ichr(filename, 0));
			write(STDERR, ": No such file or directory\n", 28);
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

static void	child_process(int *p, char **argv, char **envp, int fdin)
{
	char	**cmd;
	char	*f_path;

	close(p[0]);
	dup2(fdin, STDIN_FILENO);
	dup2(p[1], STDOUT_FILENO);
	close(p[1]);
	if (fdin == -1)
		exit(0);
	cmd = str_split(argv[2], ' ');
	get_path(cmd[0], envp, &f_path, 0);
	if (execve(f_path, cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_matrix(cmd);
		free(f_path);
		exit(0);
	}
}

static void	father_process(int *p, char **argv, char **envp, int fdout)
{
	char	**cmd;
	char	*f_path;
	int		corr;

	wait(0);
	close(p[1]);
	dup2(p[0], 0);
	close(p[0]);
	dup2(fdout, 1);
	cmd = str_split(argv[3], ' ');
	corr = get_path(cmd[0], envp, &f_path, 0);
	if (execve(f_path, cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_matrix(cmd);
		if (corr == 1)
			free(f_path);
		exit(0);
	}
}

int	funci(char **argv, char **envp)
{
	pid_t	pid;
	int		p[2];
	int		fdin;
	int		fdout;

	fdin = openfile(argv[1], INFILE);
	fdout = openfile(argv[4], OUTFILE);
	if (fdout == -1)
		return (1);
	if (pipe(p) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Fork failed\n", 2);
		return (0);
	}
	if (pid == 0)
		child_process(p, argv, envp, fdin);
	else
		father_process(p, argv, envp, fdout);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;

	if (argc != 5)
	{
		write(STDERR, "Invalid number of arguments.\n", 29);
		return (1);
	}
	pid = fork();
	if (pid == 0)
		funci(argv, envp);
	else
		wait(0);
	return (0);
}

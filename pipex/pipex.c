/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:14:09 by apancar           #+#    #+#             */
/*   Updated: 2023/12/21 09:36:42 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (127);
}

void	child_process(int *fd, char *av[], char **env)
{
	char	**flags;
	int		input;
	char	*env1;

	flags = ft_split(av[2], ' ');
	close(fd[0]);
	input = open(av[1], O_RDONLY, 0644);
	if (input == -1)
		msg_error(ERR_FILE);
	dup2(fd[1], 1);
	close(fd[1]);
	dup2(input, 0);
	close(input);
	env1 = find_env(env, flags[0]);
	if (execve(env1, flags, env) == -1)
		msg_error(ERR_CMD);
}

void	main_process(int *fd, char *av[], char **env)
{
	char	**flags;
	char	*env1;
	int		output;

	output = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output == -1)
		msg_error(ERR_FILE);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(output, 1);
	flags = ft_split(av[3], ' ');
	env1 = find_env(env, flags[0]);
	close(output);
	if (execve(env1, flags, env) == -1)
		msg_error(ERR_EXEC);
}

int	main(int ac, char *av[], char **env)
{
	int		pid;
	int		fd[2];

	if (ac != 5)
		return (msg(ERR_FILE));
	if (pipe(fd) == -1)
		exit (127);
	pid = fork();
	if (pid == -1)
		exit(127);
	else if (pid == 0)
		child_process(fd, av, env);
	else
		main_process(fd, av, env);
	return (0);
}

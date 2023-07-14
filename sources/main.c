/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:40:51 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/13 16:44:18 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char *command, char **command_paths)
{
	char	*command_path;
	int		i;

	i = 0;
	while (command_paths[i])
	{
		command_path = ft_strjoin(command_paths[i], "/");
		command_path = ft_strjoin(command_path, command);
		if (access(command_path, F_OK) == 0)
			return (command_path);
		free(command_path);
		i++;
	}
	return (NULL);
}

void	ft_pipex(t_pipex pipex, char **envp)
{
	char	*cmd1_path;
	char	*cmd2_path;

	pipex.command_paths = get_paths(envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		found_error(FORK_ERROR);
	if (pipex.pid1 == 0)
	{
		dup2(pipex.pipe_fd[1], STDOUT_FILENO);
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		cmd1_path = get_cmd_path(pipex.cmd1[0], pipex.command_paths);
		execve(cmd1_path, pipex.cmd1, envp);
	}

	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		found_error(FORK_ERROR);
	if (pipex.pid2 == 0)
	{
		dup2(pipex.pipe_fd[0], STDIN_FILENO);
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		cmd2_path = get_cmd_path(pipex.cmd2[0], pipex.command_paths);
		execve(cmd2_path, pipex.cmd2, envp);
	}
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}

void	store_args(char **argv, t_pipex *pipex)
{
	pipex->in_file = ft_strdup(argv[1]);
	pipex->out_file = ft_strdup(argv[4]);
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		found_error(INV_NUM_ARGS);
	pipex.in_file_fd = open(argv[1], O_RDONLY);
	if (pipex.in_file_fd == -1)
		found_error(INV_IN_FILE);
	pipex.out_file_fd = open(argv[4], O_WRONLY);
	if (pipex.out_file_fd == -1)
		found_error(INV_OUT_FILE);
	store_args(argv, &pipex);
	if (pipe(pipex.pipe_fd) == -1)
		found_error(PIPE_ERROR);
	ft_pipex(pipex, envp);
	return (0);
}

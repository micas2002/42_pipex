/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:40:44 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/17 14:44:04 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(t_pipex pipex, char **envp)
{
	char	*cmd1_path;

	dup2(pipex.in_file_fd, STDIN_FILENO);
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	cmd1_path = get_cmd_path(pipex.cmd1[0], pipex.command_paths);
	execve(cmd1_path, pipex.cmd1, envp);
}

void	child_two(t_pipex pipex, char **envp)
{
	char	*cmd2_path;

	dup2(pipex.out_file_fd, STDOUT_FILENO);
	dup2(pipex.pipe_fd[0], STDIN_FILENO);
	close(pipex.pipe_fd[1]);
	cmd2_path = get_cmd_path(pipex.cmd2[0], pipex.command_paths);
	execve(cmd2_path, pipex.cmd2, envp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:40:44 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/17 19:28:07 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(t_pipex pipex, char **envp)
{
	char	*cmd1_path;

	if (dup2(pipex.in_file_fd, STDIN_FILENO) == -1)
		found_error(DUP_ERROR);
	if (dup2(pipex.pipe_fd[1], STDOUT_FILENO) == -1)
		found_error(DUP_ERROR);
	close(pipex.pipe_fd[0]);
	cmd1_path = get_cmd_path(pipex.cmd1[0], pipex.command_paths);
	if (execve(cmd1_path, pipex.cmd1, envp) == -1)
		found_error(EXECUTE_ERROR);
}

void	child_two(t_pipex pipex, char **envp)
{
	char	*cmd2_path;

	if (dup2(pipex.out_file_fd, STDOUT_FILENO) == -1)
		found_error(DUP_ERROR);
	if (dup2(pipex.pipe_fd[0], STDIN_FILENO) == -1)
		found_error(DUP_ERROR);
	close(pipex.pipe_fd[1]);
	cmd2_path = get_cmd_path(pipex.cmd2[0], pipex.command_paths);
	if (execve(cmd2_path, pipex.cmd2, envp) == -1)
		found_error(EXECUTE_ERROR);
}

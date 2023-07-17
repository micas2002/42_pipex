/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:41:02 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/16 14:22:50 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft.h"

//errors

# define INV_NUM_ARGS 1
# define INV_IN_FILE 2
# define INV_OUT_FILE 3
# define PIPE_ERROR 4
# define FORK_ERROR 5

typedef struct s_pipex
{
	int		pipe_fd[2];
	int		in_file_fd;
	int		out_file_fd;
	char	**cmd1;
	char	**cmd2;
	char	*in_file;
	char	*out_file;
	char	**command_paths;
	int		pid1;
	int		pid2;
}t_pipex;

//main.c

void	store_args(char **argv, t_pipex *pipex);
void	ft_pipex(t_pipex pipex, char **envp);

//error_handling.c

void	found_error(int error);

//command_paths.c

char	**get_paths(char **envp);

#endif
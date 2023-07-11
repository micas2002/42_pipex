/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:40:51 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/11 16:22:31 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	store_args(char **argv, t_pipex *pipex)
{
	pipex->in_file = ft_strdup(argv[1]);
	pipex->out_file = ft_strdup(argv[4]);
	pipex->cmd1 = ft_strdup(argv[2]);
	pipex->cmd2 = ft_strdup(argv[3]);
}

int	main(int argc, char **argv)
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
}

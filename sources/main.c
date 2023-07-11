/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:40:51 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/11 15:12:22 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
}

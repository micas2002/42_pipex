/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:05:27 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/17 19:27:51 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	found_error(int error)
{
	if (error == INV_NUM_ARGS)
		ft_putstr_fd("Error: Wrong number of arguments.\n", 2);
	else if (error == INV_IN_FILE)
		ft_putstr_fd("Error: Input file does not exist.\n", 2);
	else if (error == INV_OUT_FILE)
		ft_putstr_fd("Error: Output file does not exist.\n", 2);
	else if (error == PIPE_ERROR)
		ft_putstr_fd("Error: Pipe error.\n", 2);
	else if (error == FORK_ERROR)
		ft_putstr_fd("Error: Fork error.\n", 2);
	else if (error == DUP_ERROR)
		ft_putstr_fd("Error: Dup error.\n", 2);
	else if (error == EXECUTE_ERROR)
		ft_putstr_fd("Error: Execute error.\n", 2);
	exit(1);
}

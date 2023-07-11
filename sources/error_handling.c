/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:05:27 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/11 15:30:13 by mibernar         ###   ########.fr       */
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
	exit(1);
}

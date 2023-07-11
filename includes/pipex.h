/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:41:02 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/11 15:11:53 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

//errors

# define INV_NUM_ARGS 1
# define INV_IN_FILE 2
# define INV_OUT_FILE 3

typedef struct s_pipex
{
	int	in_file_fd;
	int	out_file_fd;
}t_pipex;

//main.c

//error_handling.c

void	found_error(int error);

#endif
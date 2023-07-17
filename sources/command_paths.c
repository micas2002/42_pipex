/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:39:36 by mibernar          #+#    #+#             */
/*   Updated: 2023/07/17 14:42:09 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

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

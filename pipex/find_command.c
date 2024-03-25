/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:28:51 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/25 18:42:47 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_command_path(char *long_cmd, char **envp)
{
	char	**cmd;
	char	**path_arr;
	char	*path;
	char	*cmd_path;

	path = find_path(envp);
	if (!path)
		return (NULL);
	path_arr = ft_split(path, ':');
	if (!path_arr)
		return (NULL);
	cmd = ft_split(long_cmd, ' ');
	if (!cmd)
		return (free_split(path_arr), NULL);
	cmd_path = check_if_cmd_exists(path_arr, cmd[0]);
	free_split(cmd);
	free_split(path_arr);
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}

char	*check_if_cmd_exists(char **path_arr, char *cmd)
{
	int		counter;
	char	*path_line;

	counter = 0;
	path_line = NULL;
	while (path_arr[counter])
	{
		path_line = add_cmd_to_line_in_path(path_arr[counter], cmd);
		if (!path_line)
			return (NULL);
		if (if_path_to_cmd(path_line))
			return (path_line);
		free(path_line);
		counter++;
	}
	return (NULL);
}

int	if_path_to_cmd(char *path_line)
{
	if (access(path_line, F_OK) == -1)
		return (0);
	return (1);
}

char	*add_cmd_to_line_in_path(char *line, char *cmd)
{
	char	*path_line;

	path_line = ft_strjoin(line, cmd);
	if (!path_line)
	{
		free(path_line);
		return (NULL);
	}
	return (path_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:28:51 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/06 19:05:49 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_command(char *cmd, char **envp)
{
	char	*path;
	char	*short_cmd;
	char	*cmd_path;
	char	**path_arr;

	if (!(path = find_path(envp)) || !(path_arr = parse_path(path)) \
		|| !(short_cmd = parse_cmd(cmd)))
		return (NULL);
	cmd_path = check_if_cmd_exists(path_arr, short_cmd);
	free(short_cmd);
	free_split(path_arr);
	if (!cmd_path)
		return (NULL);
	ft_printf("The cmd exists!\n");
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
		if (!(path_line = add_cmd_to_line_in_path(path_arr[counter], cmd)))
			return (NULL);
		if (if_path_to_cmd(path_line))
			return (path_line);
		free(path_line);
		counter++;
	}
	return (NULL);
}

int		if_path_to_cmd(char *path_line)
{
	if (access(path_line, F_OK) == -1)
	{
		// ft_printf("cmd doesn't exist on this path\n");
		return (0);
	}
	return (1);
}

char	*add_cmd_to_line_in_path(char *line, char *cmd)
{
	char	*path_line;

	path_line = ft_strjoin(line, cmd);
	if (!path_line)
		return (NULL);
	return (path_line);
}

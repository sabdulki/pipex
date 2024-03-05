/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:28:51 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/05 22:08:11 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_command(char *cmd, char **envp)
{
	char	*path;
	char	*short_cmd;
	char	**path_arr;

	if (!(path = find_path(envp)))
		return (1);
	path_arr = parse_path(path);
	if (!(short_cmd = parse_cmd(cmd)))
		return (1);
	if (!check_if_cmd_exists(path_arr, short_cmd))
	{
		free(short_cmd);
		return (1);
	}
	
}

int	check_if_cmd_exists(char **path_arr, char *cmd)
{
	int		counter;
	char	*path_line;
	
	counter = 0;
	path_line = NULL;
	while(path_arr[counter])
	{
		if(!(path_line = add_cmd_to_line_in_path(path_arr[counter], cmd)))
			return (1);
		// function which will check if there is this cmd on this path
		// if there is a cmd on this puth -> break &&  return 
			
		counter++;
	}
}

char	*add_cmd_to_line_in_path(char *line, char *cmd)
{
	int		i;
	int		j;
	int		cmd_len;
	char	*path_line;

	i = 0;
	j = 0;
	cmd_len = ft_strlen(cmd);
	while(line[i])
		i++;
	path_line = malloc(sizeof(char) * (i + cmd_len + 1));
	if (!path_line)
		return (NULL);
	while(cmd[j])
	{
		path_line[i] = cmd[j];
		i++;
		j++;
	}
	path_line[i] = '\0';
	return (path_line);
}


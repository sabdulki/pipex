/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:20:47 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/14 20:13:41 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd_info	*init_cmd_info(char **envp, char *cmd)
{
	t_cmd_info *cmd_info;

	cmd_info = malloc(sizeof(t_cmd_info));
	if (!cmd_info)
		return (NULL);
	cmd_info->cmd = cmd_to_execute(cmd);
	cmd_info->envp = envp;
	cmd_info->cmd_path = find_command(cmd, envp);
	if (!cmd_info->cmd_path)
	{
		ft_printf("no such cmd\n"); 
		return (0);
	}
	printf("created a cmd '%s'!\n", cmd_info->cmd[0]);
	return (cmd_info);
}

void	free_cmd(t_cmd_info *cmd)
{
	free(cmd->cmd_path);
	free_split(cmd->cmd);
	free(cmd);
}

char	**cmd_to_execute(char *cmd)
{
	char **cmd_to_execute;
	cmd_to_execute = ft_split(cmd, ' ');
	if (!cmd_to_execute)
	{
		free_split(cmd_to_execute);
		return (NULL);
	}
	return (cmd_to_execute);
}

int	ft_file_fd(t_cmd_info *cmd, char *file, int cmd_index, int ac)
{
	int		fd;
	char	*file_name;
	mode_t	mode;
	if (cmd_index == 2 && file) //first cmd
	{
		fd = open(file, O_RDONLY);
		cmd->inout = 'i';
		
	}
	else if (cmd_index == ac - 2) // last cmd
	{
		file_name = "outfile";
		mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, mode);
		cmd->inout = 'o';
	}
	else
	{
		fd = 0;
		cmd->inout = 'c';
	}
	if (fd == -1)
		return (errno);
	// printf("file fd for this cmd is: %d\n", fd);
	close(fd);
	return (fd);
}
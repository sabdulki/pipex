/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:20:47 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/22 19:17:32 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd_info	*init_all_cmds(int ac, char **av, char **envp)
{
	int			i;
	int			var;
	int			counter;
	t_cmd_info	*cmd_head;
	t_cmd_info	*cmd;

	i = 0;
	counter = 2; // first cmd's index in av[]
	var = ac - 3;
	cmd_head = NULL;
	while (i < var) // || counter < var)
	{
		if (!(cmd = init_cmd(ac, counter, av, envp)))
		{
			if (cmd_head)
					free_list(cmd_head);
			return (NULL);
		}
		if (!(cmd_head = add_cmd_to_list(cmd, cmd_head)))
			return (NULL);
		counter++;
		i++;
	}
	return (cmd_head);
}

t_cmd_info	*init_cmd(int ac, int counter, char **av, char **envp)
{
	t_cmd_info	*cmd;
	char		*file;

	if (counter == 2)
		file = av[1];
	else
		file = NULL;
	cmd = init_cmd_info(envp, av[counter], counter - 1);
	if (!cmd)
		return (NULL);
	cmd->file_fd = ft_file_fd(cmd, file, counter, ac);
	if (cmd->file_fd == -1)
		return (NULL);
	return (cmd);
}

t_cmd_info	*init_cmd_info(char **envp, char *cmd, int index)
{
	t_cmd_info	*cmd_info;

	cmd_info = malloc(sizeof(t_cmd_info));
	if (!cmd_info)
		return (NULL);
	cmd_info->cmd = NULL;
	cmd_info->cmd_path = NULL;
	cmd_info->connection = NULL;
	cmd_info->index = index;
	cmd_info->cmd = ft_split(cmd, ' ');
	if (!cmd_info->cmd)
	{
		free_cmd(cmd_info);
		return (NULL);
	}
	cmd_info->envp = envp;
	cmd_info->cmd_path = find_command_path(cmd, envp);
	if (!cmd_info->cmd_path)
	{
		ft_printf("command not found\n");
		free_cmd(cmd_info);
		return (NULL);
	}
	cmd_info->connection = malloc(sizeof(int) * 2);
	if (!cmd_info->connection)
	{
		free_cmd(cmd_info);
		return (NULL);
	}
	ft_printf("created a cmd '%s'!\n", cmd_info->cmd[0]);
	return (cmd_info);
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
		mode = S_IRUSR | S_IWUSR;
		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, mode);
		cmd->inout = 'o';
	}
	else
	{
		fd = 0;
		cmd->inout = 'c';
	}
	if (fd == -1)
		return (-1);
	// printf("file fd for this cmd is: %d\n", fd);
	return (fd);
}

int	free_cmd(t_cmd_info *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->cmd_path)
		free(cmd->cmd_path);
	if (cmd->cmd)
		free_split(cmd->cmd);
	if (cmd->connection)
		free(cmd->connection);
	free(cmd);
	return (1);
}

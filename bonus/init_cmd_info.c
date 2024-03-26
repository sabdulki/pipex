/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:20:47 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/26 18:54:46 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd_info	*init_all_cmds(int ac, char **av, char **envp)
{
	int			i;
	int			cmd_amount;
	int			counter;
	t_cmd_info	*cmd_head;
	t_cmd_info	*cmd;

	i = 0;
	counter = 2;
	if (!is_here_doc(av))
		cmd_amount = ac - 3;
	else
		cmd_amount = ac - 4;
	cmd_head = NULL;
	while (i++ < cmd_amount)
	{
		cmd = init_cmd(ac, counter, av, envp);
		if (!cmd)
		{
			if (cmd_head)
				free_list(cmd_head);
			exit(127);
		}
		cmd_head = add_cmd_to_list(cmd, cmd_head);
		counter++;
	}
	return (cmd_head);
}

t_cmd_info	*init_cmd(int ac, int counter, char **av, char **envp)
{
	t_cmd_info	*cmd;
	char		*file;

	if (!is_here_doc(av)) // input WITHOUT here_doc
		cmd = init_cmd_info(envp, av[counter], counter - 1);
	else // input WITH here_doc
		cmd = init_cmd_info(envp, av[counter + 1], counter - 1);
	if (!cmd)
		return (NULL);
	if (cmd->index == 1 && is_here_doc(av))
	{
		cmd->file_fd = ft_here_doc(av[2]);
		if (!cmd->file_fd)
			return(NULL);
		cmd->inout = 'i';
	}
	else
	{
		if (counter == 2)
			file = av[1];
		else
			file = NULL;
		if (!is_here_doc(av))
			cmd->file_fd = ft_file_fd(cmd, file, counter, ac);
		else
			cmd->file_fd = ft_file_fd(cmd, file, counter, ac - 1);
		if (cmd->file_fd == -1)
			return (NULL);
	}
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
	cmd_info->status = 0;
	cmd_info->index = index;
	cmd_info->envp = envp;
	if (!(init(cmd_info, cmd, envp)))
		return (NULL);
	return (cmd_info);
}

int	init(t_cmd_info *cmd_info, char *cmd, char**envp)
{
	cmd_info->cmd = ft_split(cmd, ' ');
	if (!cmd_info->cmd)
	{
		free_cmd(cmd_info);
		return (0);
	}
	cmd_info->cmd_path = find_command_path(cmd_info->cmd[0], envp);
	if (!cmd_info->cmd_path)
	{
		free_cmd(cmd_info);
		write(2, "command not found\n", 19);
		return (0);
	}
	cmd_info->connection = malloc(sizeof(int) * 2);
	if (!cmd_info->connection)
	{
		free_cmd(cmd_info);
		return (0);
	}
	return (1);
}

int	ft_file_fd(t_cmd_info *cmd, char *file, int counter, int ac)
{
	int		fd;
	char	*file_name;
	mode_t	mode;

	if (counter == 2 && file)
	{
		fd = open(file, O_RDONLY);
		cmd->inout = 'i';
	}
	else if (counter == ac - 2)
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
	return (fd);
}

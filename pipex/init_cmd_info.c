/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:20:47 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/21 15:46:48 by sabdulki         ###   ########.fr       */
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
			return (0); // already freed in previous function
		if (!(cmd_head = add_cmd_to_list(cmd, cmd_head)))
		{
			free_list(cmd_head);
			return (0);
		}
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
	if (!(cmd = init_cmd_info(envp, av[counter], counter - 1)) \
		|| !(cmd->file_fd = ft_file_fd(cmd, file, counter, ac)))
	{
		free_cmd(cmd);
		return (0);
	}
	// printf("which fd: '%c'\n", cmd->inout);
	return (cmd);
}

t_cmd_info	*init_cmd_info(char **envp, char *cmd, int index)
{
	t_cmd_info *cmd_info;

	cmd_info = malloc(sizeof(t_cmd_info));
	if (!cmd_info)
		return (NULL);
	cmd_info->index = index;
	cmd_info->cmd = ft_split(cmd, ' ');
	if (!cmd_info->cmd)
	{
		free_split(cmd_info->cmd);
		return (NULL);
	}
	cmd_info->envp = envp;
	cmd_info->cmd_path = find_command(cmd, envp);
	if (!cmd_info->cmd_path)
	{
		ft_printf("no such cmd\n"); 
		return (0);
	}
	cmd_info->connection = malloc(sizeof(int) * 2);
	if (!cmd_info->connection)
	{
		free_cmd(cmd_info);
		return (0);
	}
	printf("created a cmd '%s'!\n", cmd_info->cmd[0]);
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
		return (errno);
	printf("file fd for this cmd is: %d\n", fd);
	// close(fd);
	return (fd);
}

void	free_cmd(t_cmd_info *cmd)
{
	free(cmd->cmd_path);
	free_split(cmd->cmd);
	free(cmd);
}

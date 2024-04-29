/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:11:22 by sabdulki          #+#    #+#             */
/*   Updated: 2024/04/29 21:26:09 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_all_cmds(t_cmd_info *cmd_list, int *pfd)
{
	t_cmd_info	*cmd;

	cmd = cmd_list;
	while (cmd)
	{
		execute_cmd(cmd, cmd_list, pfd);
		cmd = cmd->next;
	}
	return (1);
}

int	execute_cmd(t_cmd_info *cmd, t_cmd_info *cmd_list, int *pfd)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		dup2(cmd->connection[0], STDIN_FILENO);
		close(cmd->connection[0]);
		dup2(cmd->connection[1], STDOUT_FILENO);
		close(cmd->connection[1]);
		status = execve(cmd->cmd_path, cmd->cmd, cmd->envp);
		free_list(cmd_list);
		close_free_pfd(pfd);
		exit(status);
	}
	else
	{
		close(cmd->connection[0]);
		close(cmd->connection[1]);
		return (1);
	}
	return (0);
}

int	wait_cmds(t_cmd_info *cmd_head)
{
	int	i;
	int	size;
	int	status;

	i = 0;
	size = list_size(cmd_head);
	while (i < size)
	{
		wait(&status);
		status = WEXITSTATUS(status);
		i++;
	}
	return (status);
}

int	list_size(t_cmd_info *cmd_list)
{
	t_cmd_info	*current_cmd;
	int			size;

	size = 0;
	current_cmd = cmd_list;
	while (current_cmd)
	{
		size++;
		current_cmd = current_cmd->next;
	}
	return (size);
}

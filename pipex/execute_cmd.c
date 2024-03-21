/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:11:22 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/21 16:46:14 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_all_cmds(t_cmd_info *cmd_list)
{
	t_cmd_info	*cmd;

	cmd = cmd_list;
	while (cmd)
	{
		if (!execute_cmd(cmd))
			return (0);
		cmd = cmd->next;
	}
	return (1);
}

int	execute_cmd(t_cmd_info *cmd) //, int cmd_pipe[2]) //, int out_pipe[2])
{
	int	pid;
	int	status;

	pid = fork();
	if (pid < 0)
	{
		printf("pid < 0\n");
		return (0);
	}
	if (pid == 0)
	{
		printf("id = %d. I'm child process for '%s'\n", pid, cmd->cmd[0]);
		// redirect_fd(pfd, cmd);
		//create 2 dup2
		dup2(cmd->connection[0], STDIN_FILENO);
		close(cmd->connection[0]);
		dup2(cmd->connection[1], STDOUT_FILENO);
		close(cmd->connection[1]);
		// if (cmd->file_fd != -1)
		// close(cmd->file_fd);
		status = execve(cmd->cmd_path, cmd->cmd, cmd->envp);
		//free linked list for THIS process
		free_list(cmd);
		//if successful - returns nothing
		//if error - return -1
		printf("status of '%s' is: %d", cmd->cmd[0], status);
		exit(EXIT_FAILURE);
	}
	else 
	{
		printf("\tid = %d. I'm parent process in ft_execute_cmd for '%s'\n", pid, cmd->cmd[0]);
		// close(cmd->file_fd);
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
	int	child_pid;

	i = 0;
	size = list_size(cmd_head);
	// printf("size: %d\n", size);
	while (i < size)
	{
		child_pid = wait(&status);
		if (WIFEXITED(status))
			printf("\tChild process with PID %d, cmd ' ' exited successfuly \
			with status: %d\n", child_pid, WEXITSTATUS(status));
		i++;
	}
	return (1);
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

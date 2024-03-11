/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:11:22 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/11 20:26:53 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// int		execution_proc(char *cmd_path, char *cmd, char **envp)
// {
// 	if (!execute_cmd(cmd_path, cmd, envp))
// 		return (0);
	
// }

int		execute_cmd(t_cmd_info *cmd)
{
	int	fd[2];
	int	pid;
	int	status;

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		if (inout == 'i')
		{
			dup2(fd[0], cmd->file_fd);
			dup2(fd[1], STDOUT_FILENO);
		}
		else if (inout == 'o')
		{
			dup2(fd[0], STDIN_FILENO);
			dup2(fd[1], cmd->file_fd);
		}
		else
		{
			dup2(fd[0], STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
		}
		close(fd[0]);
		close(fd[1]);
		cmd->status = execve(cmd->cmd_path, cmd->cmd, cmd->envp);
		free_cmd(cmd);
		exit(status);
		//check status of execve
	}
	close(fd[0]);
	close(fd[1]);
	// waitpid(pid, NULL, 0);  i func where i call execute_cmd;
	return (1);
}

int	wait_cmds(t_cmd_info *cmd)
{
	
}
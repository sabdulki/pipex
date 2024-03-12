/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:11:22 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/12 15:20:35 by sabdulki         ###   ########.fr       */
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
	int	pfd[2];
	int	pid;
	int	status;
	int	*pip;

	if (pipe(pfd) == -1)
		return (0);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		pip = redirect_fd(pfd, cmd);
		close(pfd[0]);
		close(pfd[1]);
		// change cmd->cmd to char**!!!
		cmd->status = execve(cmd->cmd_path, cmd->cmd, cmd->envp);
		// free_cmd(cmd);
		exit(status);
		//check status of execve
	}
	close(pfd[0]);
	close(pfd[1]);
	// waitpid(pid, NULL, 0);  i func where i call execute_cmd;
	return (1);
}

int	*redirect_fd(int *pfd, t_cmd_info  *cmd)
{
	if (cmd->inout == 'i')
	{
		dup2(pfd[0], cmd->file_fd);
		dup2(pfd[1], STDOUT_FILENO);
	}
	else if (cmd->inout == 'o')
	{
		dup2(pfd[0], STDIN_FILENO);
		dup2(pfd[1], cmd->file_fd);
	}
	else
	{
		dup2(pfd[0], STDIN_FILENO);
		dup2(pfd[1], STDOUT_FILENO);
	}
	return (pfd);
}

int	wait_cmds(t_cmd_info *cmd_head)
{
	
}
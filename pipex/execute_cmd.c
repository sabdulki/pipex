/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:11:22 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/15 15:15:19 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		execute_cmd(t_cmd_info *cmd, int in_pipe[2], int out_pipe[2])
{
	int	pfd[2];
	int	pid;
	int	status;

	if (pipe(pfd) == -1) // incorrect
		return (0);
	pid = fork();
	if (pid < 0)
	{
		printf("pid < 0\n");
		return (0);
	}
	if (pid == 0)
	{
		
		printf("id = %d. I'm child process for '%s'\n", pid, cmd->cmd[0]);
		redirect_fd(pfd, cmd);
		// close(pip[0]);
		// close(pip[1]);
		close(pfd[0]);
		close(pfd[1]);
		status = execve(cmd->cmd_path, cmd->cmd, cmd->envp);
		//free linked list for THIS process
		free_list(cmd);
		//if successful - returns nothing
		//if error - return -1
		printf("status of '%s' is: %d", cmd->cmd[0], status);
		exit(EXIT_FAILURE);
	}
	else {
		printf("\tid = %d. I'm parent process in ft_execute_cmd for '%s'\n", pid, cmd->cmd[0]);
		close(pfd[0]);
		close(pfd[1]);
		return (1);
	}
	// waitpid(pid, NULL, 0);  i func where i call execute_cmd;
	return (0);
}

int	*redirect_fd(int *pfd, t_cmd_info *cmd)
{
	if (cmd->inout == 'i')
	{
		dup2(cmd->file_fd, STDIN_FILENO);
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);
		close(pfd[0]);

	}
	else if (cmd->inout == 'o')
	{
		dup2(pfd[0], STDIN_FILENO);
		dup2(cmd->file_fd, STDOUT_FILENO);
		close(pfd[0]);
		close(pfd[1]);
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
	t_cmd_info	*current_cmd;
	int			child_pid;

	current_cmd = cmd_head;

	while (current_cmd)
	{
		child_pid = wait(&current_cmd->status);
		if (WIFEXITED(current_cmd->status)) {
            printf("Child process with PID %d, cmd '%s' exited successfuly with status: %d\n", child_pid, current_cmd->cmd[0], WEXITSTATUS(current_cmd->status));
        }
		if (WIFSIGNALED(current_cmd->status))
            printf("Child process was terminated by signal: %d\n", WTERMSIG(current_cmd->status));
		current_cmd = current_cmd->next;
	}
	return (1);
}
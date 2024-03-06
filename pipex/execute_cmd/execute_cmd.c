/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:11:22 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/06 16:56:39 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmd.h"

int		execute_cmd(char *cmd_path, char *cmd, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (0);
	
	pid = fork();

	if (pid < 0)
	{
		free(cmd_path);
		return (0);
	}
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		//free
		execve(cmd_path, cmd, envp);
	}
	close(fd[0]);
	close(fd[1]);
	wait(pid);
	return (1);
}
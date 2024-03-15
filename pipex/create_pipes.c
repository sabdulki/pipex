/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:25:07 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/15 18:42:32 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_all_pipes(t_cmd_info *cmd_list)
{
	t_cmd_info	*cmd;
	int			*pfd1;
	int			*pfd2;
	
	pipe(pfd1);
	pipe(pfd2);
	cmd = cmd_list;
	while (cmd)
	{
		if (cmd->inout == 'i')
		{
			// 1)
			cmd->connection[0] = dup2(cmd->file_fd, STDIN_FILENO);
			// close(cmd->connection[1]);
			// dup2(pfd1[1], STDOUT_FILENO);
			// close(pfd1[0]);
			// close(pfd1[1]);
			// 2)
			cmd->connection[1] = pfd1[1]; // should write result of cmd!
			
			// dup2(pfd2[0], STDIN_FILENO);
			// close(pfd2[0]);
			// close(pfd2[1]);

		}
		if (cmd->inout == 'c')
		{
			cmd->connection[0] =  pfd1[0];
			cmd->connection[1] = pfd2[1];
		}
		if (cmd->inout == 'o')
		{
			cmd->connection[0] = pfd2[0];
			cmd->connection[1] = (cmd->file_fd, STDOUT_FILENO);
		}

		create_pipe_for_one_cmd(cmd);
		cmd = cmd->next;
	}
}

int	create_pipe_for_one_cmd(t_cmd_info *cmd)
{
	int	*pfd1; // memory will be allocated only if I use malloc
	int	*pfd2; // otherwise the memory is allocated during the compilation and i can do NOTHING with this variable 
	
	// if (pipe(pfd) == -1) // incorrect
	// 	return (0);
	pipe(pfd1);
	pipe(pfd2);
	if (cmd->inout == 'i')
	{
		// 1)
		dup2(cmd->file_fd, STDIN_FILENO);
		// dup2(pfd1[1], STDOUT_FILENO);
		// close(pfd1[0]);
		// close(pfd1[1]);
		// 2)
		dup2(pfd2[1], STDOUT_FILENO);
		// dup2(pfd2[0], STDIN_FILENO);
		// close(pfd2[0]);
		// close(pfd2[1]);

	}
	else if (cmd->inout == 'o')
	{
		close
	}
	
}
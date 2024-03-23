/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:25:07 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/23 17:24:01 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*create_all_pipes(t_cmd_info *cmd_list)
{
	t_cmd_info	*cmd;
	int			*pfd1;

	pfd1 = malloc(sizeof(int) * 2);
	pipe(pfd1);
	cmd = cmd_list;
	while (cmd)
	{
		pipe(cmd->connection);
		if (cmd->inout == 'i')
		{
			cmd->connection[0] = cmd->file_fd;
			cmd->connection[1] = pfd1[1];
		}
		if (cmd->inout == 'o')
		{
			cmd->connection[0] = pfd1[0];
			cmd->connection[1] = cmd->file_fd;
		}
		cmd = cmd->next;
	}
	return (pfd1);
}

int	close_free_pfd(int *pfd)
{
	close(pfd[0]);
	close(pfd[1]);
	free(pfd);
	return (1);
}

//call dup2 ONLY in child process

		// if (cmd->inout == 'c')
		// {
		// 	cmd->connection[0] =  pfd1[0];
		// 	cmd->connection[1] = pfd2[1];
		// }
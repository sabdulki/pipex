/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:25:07 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/22 19:17:58 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*create_all_pipes(t_cmd_info *cmd_list)
{
	t_cmd_info	*cmd;
	int			*pfd1;

	pfd1 = malloc(sizeof(int) * 2);
	pipe(pfd1); // 4 fd-s - 2 for child and 2 for parent
	cmd = cmd_list;
	while (cmd)
	{
		pipe(cmd->connection);
		// printf("cmd-inout: %c\n", cmd->inout);
		if (cmd->inout == 'i')
		{
			cmd->connection[0] = cmd->file_fd;
			cmd->connection[1] = pfd1[1];
		}
		// if (cmd->inout == 'c')
		// {
		// 	cmd->connection[0] =  pfd1[0];
		// 	cmd->connection[1] = pfd2[1];
		// }
		if (cmd->inout == 'o')
		{
			cmd->connection[0] = pfd1[0];
			cmd->connection[1] = cmd->file_fd;
		}
		cmd = cmd->next;
	}
	//call dup2 ONLY in child process
	return (pfd1);
}

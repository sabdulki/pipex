/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:25:07 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/25 20:16:28 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*create_all_pipes(t_cmd_info *cmd_list)
{
	t_cmd_info	*cmd;
	int			size;
	int			*pfd1;
	int			*pfd_last;
	int			**pipe_arr;

	pfd1 = malloc(sizeof(int) * 2);
	if (!pfd1)
		return (NULL);
	pipe(pfd1);
	size = list_size(cmd_list);
	if (size > 2)
	{
		pipe_arr = malloc(sizeof(int) * 2 * (size - 1));
		if (!pipe_arr)
			return (NULL);
	}
	cmd = cmd_list;
	while (cmd)
	{
		pipe(cmd->connection);
		if (cmd->inout == 'i')
		{
			cmd->connection[0] = cmd->file_fd;
			cmd->connection[1] = pfd1[1];
		}
		if (cmd->inout == 'c')
		{
			pfd_last = multiple_pipes(cmd, pfd1, size);
		}
		if (cmd->inout == 'o')
		{
			cmd->connection[0] = pfd_last[0];
			cmd->connection[1] = cmd->file_fd;
		}
		cmd = cmd->next;
	}
	return (pfd1);
}

int	*multiple_pipes(t_cmd_info *cmd, int *pfd1, int size)
{
	int	i;
	int	*pfd_current;

	i = 0;
	pfd_current = malloc(sizeof(int) * 2);
	if (!pfd_current)
		return (NULL);
	pipe(pfd_current);
	while (i < size - 2)
	{
		cmd->connection[0] = pfd1[0];
		cmd->connection[1] = pfd_current[1];

	}	
	
}

int	close_free_pfd(int *pfd)
{
	close(pfd[0]);
	close(pfd[1]);
	free(pfd);
	return (1);
}

//call dup2 ONLY in child process

		if (cmd->inout == 'c')
		{
			cmd->connection[0] =  pfd1[0];
			cmd->connection[1] = pfd2[1];
		}
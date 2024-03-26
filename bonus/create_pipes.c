/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:25:07 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/26 19:36:27 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**create_all_pipes(t_cmd_info *cmd_list)
{
	int			i;
	int			*pfd;
	int			**pipe_arr;
	t_cmd_info	*cmd;

	pipe_arr = malloc(sizeof(int*) * (list_size(cmd_list)));
	if (!pipe_arr)
		return (NULL);
	i = 0;
	cmd = cmd_list;
	while (cmd)
	{
		if (cmd->inout != 'o')
		{
			pfd = malloc(sizeof(int) * 2);
			if (!pfd || pipe(pfd) != 0)
				return (NULL);
			pipe_arr[i] = pfd;
		}
		if (cmd->inout == 'i')
		{
			cmd->connection[0] = cmd->file_fd;
			cmd->connection[1] = pfd[1];
		}
		if (cmd->inout == 'c')
		{
			cmd->connection[0] = pipe_arr[i - 1][0];
			cmd->connection[1] = pfd[1];
		}
		if (cmd->inout == 'o')
		{
			cmd->connection[0] = pipe_arr[i - 1][0];
			cmd->connection[1] = cmd->file_fd;
		}
		cmd = cmd->next;
		i++;
	}
	pipe_arr[i - 1] = NULL;
	return (pipe_arr);
}

int	close_free_pfd(int **pipe_arr)
{
	int i;

	i = 0;
	while (pipe_arr[i])
	{
		close(pipe_arr[i][0]);
		close(pipe_arr[i][1]);
		free(pipe_arr[i]);
		i++;
	}
	free(pipe_arr);
	return (1);
}

//call dup2 ONLY in child process

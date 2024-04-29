/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_create_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:25:07 by sabdulki          #+#    #+#             */
/*   Updated: 2024/04/29 20:59:29 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	**create_all_pipes(t_cmd_info *cmd_list)
{
	int			i;
	int			**pipe_arr;
	t_cmd_info	*cmd;

	pipe_arr = malloc(sizeof(int *) * (list_size(cmd_list)));
	if (!pipe_arr)
		return (NULL);
	i = 0;
	cmd = cmd_list;
	while (cmd)
	{
		pipe_arr = fill_pipes(cmd, pipe_arr, i);
		if (!pipe_arr)
			return (NULL);
		cmd = cmd->next;
		i++;
	}
	pipe_arr[i - 1] = NULL;
	return (pipe_arr);
}

int	**fill_pipes(t_cmd_info *cmd, int **pipe_arr, int i)
{
	int			*pfd;

	if (cmd->inout != 'o')
	{
		pfd = create_a_pipe(pipe_arr);
		if (!pfd)
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
	return (pipe_arr);
}

int	*create_a_pipe(int **pipe_arr)
{
	int			*pfd;

	pfd = malloc(sizeof(int) * 2);
	if (!pfd)
	{
		close_free_pipe_arr(pipe_arr);
		return (NULL);
	}
	if (pipe(pfd) != 0)
	{
		free(pfd);
		close_free_pipe_arr(pipe_arr);
		return (NULL);
	}
	return (pfd);
}

int	close_free_pipe_arr(int **pipe_arr)
{
	int	i;

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

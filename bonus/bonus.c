/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:35:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/04/29 21:21:10 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

// return (1) == return TRUE | return (0) == return FALSE

int	main(int ac, char **av, char **envp)
{
	t_cmd_info	*cmd_list;
	int			status_wait;

	if (ac < 5)
		return (0);
	if (!is_here_doc(av))
	{
		if (!check_infile(av[1]))
			return (0);
	}
	cmd_list = main_process(ac, av, envp);
	if (!cmd_list)
		return (0);
	status_wait = wait_cmds(cmd_list);
	free_list(cmd_list);
	return (status_wait);
}

t_cmd_info	*main_process(int ac, char **av, char **envp)
{
	t_cmd_info	*cmd_list;
	int			**pipe_arr;

	cmd_list = init_all_cmds(ac, av, envp);
	if (!cmd_list)
		return (NULL);
	// printf("initialized all cmds!\n");
	pipe_arr = create_all_pipes(cmd_list);
	if (!pipe_arr)
	{
		free_list(cmd_list);
		return (NULL);
	}
	// printf("successfully created a pipe!\n");
	execute_all_cmds(cmd_list, pipe_arr);
	close_free_pipe_arr(pipe_arr);
	// printf("executed!\n");
	return (cmd_list);
}

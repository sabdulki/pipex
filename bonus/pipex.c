/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:35:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/25 20:00:06 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// return (1) == return TRUE | return (0) == return FALSE

int	main(int ac, char **av, char **envp)
{
	t_cmd_info	*cmd_list;
	int			status_wait;

	if (ac != 5)
		return (0);
	if (!check_infile(av[1]))
		return (0);
	cmd_list = main_process(ac, av, envp);
	if (!cmd_list)
	{
		ft_printf("smth wrong in execution");
		return (0);
	}
	printf("calling wait()\n");
	status_wait = wait_cmds(cmd_list);
	free_list(cmd_list);
	printf("freed list\n");
	return (status_wait);
}

t_cmd_info	*main_process(int ac, char **av, char **envp)
{
	t_cmd_info	*cmd_list;
	int			*pfd;

	cmd_list = init_all_cmds(ac, av, envp);
	if (!cmd_list)
		return (NULL);
	printf("initialized all cmds!\n");
	pfd = create_all_pipes(cmd_list);
	if (!pfd)
	{
		free_list(cmd_list);
		close_free_pfd(pfd);
		return (NULL);
	}
	printf("successfully created a pipe!\n");
	if (!execute_all_cmds(cmd_list))
	{
		free_list(cmd_list);
		close_free_pfd(pfd);
		return (NULL);
	}
	close_free_pfd(pfd);
	printf("executed!\n");
	return (cmd_list);
}

// for bonus
/*
	int	main(int ac, char **av, char **envp)
{
	int		i;
	int		var;
	int		counter;
	char	inout;

	if (ac != 5)
		return (0);
	if (!check_infile(av[1]))
	{
		ft_printf("no acces to file\n");
		return (0);
	}
	i = 0;
	counter = 2; // first cmd's index in av[]
	if (ac == 5)
		var = 1; // call the function only for first and last cmd
	else if (ac > 5)
		var = 3; // firstly call func for first cmd. while. 
		after while - func for last cmd
	while(counter < ac - var) 
	// for cmd's which don't connect with infile & outfile
	{
		if (!main_process(av[counter], envp))
			return (0);
		counter++;
	}
	return (1);
}
*/
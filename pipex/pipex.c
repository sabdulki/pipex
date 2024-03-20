/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:35:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/20 18:44:59 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// return (1) == return TRUE | return (0) == return FALSE

int	main(int ac, char **av, char **envp)
{
	t_cmd_info	*cmd_list;

	if (ac != 5)
		return (0);
	printf("%s\n", av[1]);
	if (!check_infile(av[1]))
	{
		ft_printf("no acces to file\n");
		return (0);
	}
	if (!(cmd_list = main_process(ac, av, envp)))
	{
		ft_printf("smth wrong in execution");
		return (0);
	}
	printf("calling wait()\n");
	wait_cmds(cmd_list);  // wait commnds to finish
	free_list(cmd_list);
	printf("freed list\n");
	return (1);
}

t_cmd_info	*main_process(int ac, char **av, char **envp)
{
	t_cmd_info	*cmd_list;

	if (!(cmd_list = init_all_cmds(ac, av, envp)))
		return (0); // everything already freed
	printf("initialized all cmds!\n");
	if (!(create_all_pipes(cmd_list)))
		return (0);
	printf("successfully created a pipe!\n");
	if (!(execute_all_cmds(cmd_list)))
		return (0);
	// cmd->status = execute_cmd(cmd);
	// if ((cmd->status == -1) || (cmd->status == 0))
	// {
	// 	cmd_head = add_cmd_to_list(cmd, cmd_head);
	// 	printf("status == -1\n");
	// 	return (0);
	// }text.txt "grep ab" "wc -l" outfile
	// printf("did one cmd\n");
		
	
	printf("executed!\n");
	return (cmd_list);
}

// if ((cmd->status = execute_cmd(cmd) == -1) || (cmd->status = execute_cmd(cmd) == 0 ))


	

	// if (!execution_proc(cmd)) // execute ONLY ONE cmd!!!
	// {
	// 	ft_printf("haven't execute\n");
	// 	free(cmd->cmd_path);
	// 	free(cmd);
	// 	return (0);
	// }
	//wait for all commands be executed?


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
		var = 3; // firstly call func for first cmd. while. after while - func for last cmd
	while(counter < ac - var) // for cmd's which don't connect with infile & outfile
	{
		if (!main_process(av[counter], envp))
			return (0);
		counter++;
	}
	return (1);
}
*/
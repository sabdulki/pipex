/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:35:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/14 20:08:26 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// return (1) == return TRUE | return (0) == return FALSE

int	main(int ac, char **av, char **envp)
{
	t_cmd_info	*cmd_list;

	if (ac != 5)
		return (0);
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
	int			var;
	int			counter;
	int			i;
	char		*file;
	t_cmd_info	*cmd;
	t_cmd_info	*cmd_head;
	
	i = 0;
	counter = 2; // first cmd's index in av[]
	var = ac - 3;
	cmd_head = NULL;
	while (i < var) // || counter < var)
	{
		if (counter == 2)
			file = av[1];
		else
			file = NULL;
		if (!(cmd = init_cmd_info(envp, av[counter])))
		{
			free_cmd(cmd);
			return (0);
		}
		cmd->file_fd = ft_file_fd(cmd, file, counter, ac);
		printf("which fd: '%c'\n", cmd->inout);
		// if ((cmd->status = execute_cmd(cmd) == -1) || (cmd->status = execute_cmd(cmd) == 0 ))
		cmd->status = execute_cmd(cmd);
		if ((cmd->status == -1) || (cmd->status == 0))
		{
			cmd_head = add_cmd_to_list(cmd, cmd_head);
			printf("status == -1\n");
			return (0);
		}
		printf("did one cmd\n");
		cmd_head = add_cmd_to_list(cmd, cmd_head); // first time it returns head
		counter++;
		i++;
	}
	printf("executed!\n");
	return (cmd_head);
	// после запуска всех комманд нужно закрыть все pipes

	
	// wait_cmds(cmd_head);  // wait commnds to finish
	//free_list();

	// if (!execution_proc(cmd)) // execute ONLY ONE cmd!!!
	// {
	// 	ft_printf("haven't execute\n");
	// 	free(cmd->cmd_path);
	// 	free(cmd);
	// 	return (0);
	// }
	//wait for all commands were executed?
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
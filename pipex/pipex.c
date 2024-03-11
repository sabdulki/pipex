/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:35:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/11 20:23:49 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// return (1) == return TRUE | return (0) == return FALSE

int	main(int ac, char **av, char **envp)
{
	int			var;
	int			counter;
	char		inout;
	t_cmd_info	*cmd1;
	t_cmd_info	*cmd2;
	t_cmd_list	*cmd_list;

	if (ac != 5)
		return (0);
	if (!check_infile(av[1]))
	{
		ft_printf("no acces to file\n");
		return (0);
	}
	if (!main_process(ac, av, envp))
		retrun (0); ft_printf("smth wrong in execution");
	return (1);
}

int		main_process(int ac, char **av, char **envp)
{
	int			var;
	int			counter;
	int			i;
	char		*file;
	t_cmd_info	*cmd;
	t_cmd_info	*cmd2;
	t_cmd_list	*cmd_list;
	
	i = 0;
	counter = 2; // first cmd's index in av[]
	var = ac - 3;
	while (i < var || counter < var)
	{
		if (counter == 2)
			file = av[1];
		else
			file = NULL;
		if (!(cmd = init_cmd_info(envp, av[counter], ac)))
				return (0);
		cmd->file_fd = ft_file_fd(file, counter, ac);
		cmd_list = add_cmd_to_list(cmd);
		if (!execute_cmd(cmd))
			return (0); // and free?
		counter++;
	}
	
	wait_cmds();  // wait commnds to finish
	// if (!execution_proc(cmd)) // execute ONLY ONE cmd!!!
	// {
	// 	ft_printf("haven't execute\n");
	// 	free(cmd->cmd_path);
	// 	free(cmd);
	// 	return (0);
	// }
	//wait for all commands were executed?
	return (1);
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
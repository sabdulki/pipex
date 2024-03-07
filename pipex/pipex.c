/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:35:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/07 21:18:31 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// return (1) == return TRUE | return (0) == return FALSE

int	main(int ac, char **av, char **envp)
{
	int			var;
	int			counter;
	char		inout;
	t_cmd_info	cmd1;
	t_cmd_info	cmd2;

	if (ac != 5)
		return (0);
	if (!check_infile(av[1]))
	{
		ft_printf("no acces to file\n");
		return (0);
	}
	counter = 2; // first cmd's index in av[]
	cmd1 = init_cmd_info(envp, av[counter], 'i');
	execute_cmd(cmd1, ft_file_fd(av[1], 'i')); //first cmd
	counter++:
	var = ac - 3;
	// while (counter < var) // for cmd's which don't connect with infile & outfile
	// {
	// 	if (!(cmd = init_cmd_info(envp, av[counter], 'c')))
	// 		return (0);
	// 	if (!main_process(cmd))
	// 		return (0);
	// 	counter++;
	// }
	cmd2 = init_cmd_info(envp, av[counter], 'o');
	execute_cmd(cmd2, ft_file_fd(NULL, 'o')); // last_cmd();
	//wait commnds to finish
	wait_cmds();
	return (1);
}

int		main_process(t_cmd_info cmd)
{
	if (!execution_proc(cmd)) // execute ONLY ONE cmd!!!
	{
		ft_printf("haven't execute\n");
		free(cmd->cmd_path);
		free(cmd);
		return (0);
	}
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
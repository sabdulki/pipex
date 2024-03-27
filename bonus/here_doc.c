/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:44:19 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/27 17:18:01 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_here_doc(char **av)
{
	return (ft_strncmp(av[1], "here_doc", 9));
}

int	ft_here_doc(char *limiter)
{
	char	*input;
	int		pfd[2];

	if (pipe(pfd) != 0)
		return (0);
	while (1)
	{
		ft_printf("pipe heredoc> ");
		input = get_next_line(STDIN_FILENO);
		if (ft_strncmp(limiter, input, ft_strlen(limiter)))
		{
			free(input);
			break ;
		}
		write(pfd[1], input, ft_strlen(input));
		free(input);
	}
	close(pfd[1]);
	return (pfd[0]);
}

int	which_fd(t_cmd_info *cmd, int counter, int ac, char **av)
{
	char		*file;

	if (cmd->index == 1 && is_here_doc(av))
	{
		cmd->file_fd = ft_here_doc(av[2]);
		if (!cmd->file_fd)
			return (0);
		cmd->inout = 'i';
	}
	else
	{
		if (counter == 2)
			file = av[1];
		else
			file = NULL;
		if (!is_here_doc(av))
			cmd->file_fd = ft_file_fd(cmd, file, counter, ac);
		else
			cmd->file_fd = ft_file_fd(cmd, file, counter, ac - 1);
		if (cmd->file_fd == -1)
			return (0);
	}
	return (1);
}

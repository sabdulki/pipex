/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_here_doc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:44:19 by sabdulki          #+#    #+#             */
/*   Updated: 2024/04/29 21:47:18 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
		if (!input)
		{
			close_pipe_free_input(input, pfd);
			return (-1);
		}
		if ((ft_strlen(limiter) == (ft_strlen(input) - 1)) && \
		ft_strncmp(limiter, input, ft_strlen(limiter)))
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

int	which_fd(t_cmd_info *cmd, int ac, char **av)
{
	char		*file;

	file = file_name(cmd, av, ac);
	if (cmd->index == 1 && is_here_doc(av))
	{
		cmd->file_fd = ft_here_doc(av[2]);
		cmd->inout = 'i';
	}
	else
		cmd->file_fd = ft_file_fd(cmd, file);
	if (cmd->file_fd == -1)
		return (0);

	return (1);
}

char	*file_name(t_cmd_info *cmd, char **av, int ac)
{
	char	*file;

	if (cmd->index == 1 && !is_here_doc(av))
		file = av[1];
	else if (cmd->last == 'y')
		file = av[ac - 1];
	else
		file = NULL;
	return (file);
}

void	close_pipe_free_input(char *input, int pfd[2])
{
	free(input);
	close(pfd[1]);
	close(pfd[0]);
}
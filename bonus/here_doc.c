/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:44:19 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/26 18:47:26 by sabdulki         ###   ########.fr       */
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
			break;
		write(pfd[1], input, ft_strlen(input));
		free(input);
	}
	close(pfd[1]);
	return (pfd[0]);
}

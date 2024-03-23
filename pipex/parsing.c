/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:18:13 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/23 18:36:29 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infile(char *infile)
{
	if (!infile || (open(infile, O_RDONLY)) == -1)
	{
		ft_printf("file doesn't exist\n");
		return (0);
	}
	if (access(infile, R_OK) == -1)
	{
		ft_printf("no acces to file\n");
		return (0);
	}
	return (1);
}

char	*find_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5))
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (path)
		return (path);
	return (NULL);
}

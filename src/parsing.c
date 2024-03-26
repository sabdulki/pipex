/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:18:13 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/26 20:12:55 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	check_infile(char *infile)
{
	if (!infile || (open(infile, O_RDONLY)) == -1)
	{
		ft_printf("no such file or directory: %s", infile);
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

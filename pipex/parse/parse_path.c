/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:52:01 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/07 14:11:17 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**parse_path(char *path)
{
	char	**path_arr;

	path_arr = ft_split(path, ':');
	if (!path_arr)
	{
		free_split(path_arr);
		return (0);
	}
	return (path_arr);
}

char	*find_path(char ** envp)
{
	int i;
	char *path;

	i = 0;
	path = NULL;
	while(envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5))
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (path)
	{
		printf("\tpath: %s\n", path);
		return (path);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:52:01 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/05 21:52:32 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_path(char *path)
{
	int		i;
	int		j;
	int		counter;
	char	**path_arr;

	i = 0;
	counter = 0;
	path_arr = NULL;
	while(path[i])
	{
		if (path[i] == ':')
		{
			path_arr[counter][j] = '\0';
			j = 0;
			counter++;
		}
		path_arr[counter][j] = path[i];
		j++;
		i++;
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
		return (path);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:41:10 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/11 20:28:08 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_file_fd(char *file, int cmd_index, int ac)
{
	int	fd;
	char	*file_name;
	mode_t	mode;
	if (cmd_index == 2) //first cmd
	{
		if (file)
		{
			fd = open(file, O_RDONLY);
			
		}
	}
	else if (cmd_index == ac - 1) // last cmd
	{
		file_name = "outfile";
		mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
		fd = open(file_name, O_RDONLY | O_WRONLY, mode);
	}
	else
		fd = 0;
	if (fd == -1)
		return (0);
	return (fd);
}
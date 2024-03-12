/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:41:10 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/12 14:00:43 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_file_fd(char *file, int cmd_index, int ac, t_cmd_info *cmd)
{
	int	fd;
	char	*file_name;
	mode_t	mode;
	if (cmd_index == 2) //first cmd
	{
		if (file)
		{
			fd = open(file, O_RDONLY);
			cmd->inout = 'i';
		}
	}
	else if (cmd_index == ac - 1) // last cmd
	{
		file_name = "outfile";
		mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
		fd = open(file_name, O_RDONLY | O_WRONLY, mode);
		cmd->inout = 'o';
	}
	else
		fd = 0;
	if (fd == -1)
		return (-1);
	return (fd);
}
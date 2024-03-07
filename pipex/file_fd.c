/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:41:10 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/07 19:53:42 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_file_fd(char *file, char inout)
{
	int	fd;
	char	*file_name;
	mode_t	mode;
	if (inout == 'i')
	{
		fd = open(file, O_RDONLY);
	}
	else if (inout == 'o')
	{
		file_name = "outfile";
		mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
		fd = open(file_name, O_RDONLY | O_WRONLY, mode);
	}
	if (fd == -1)
		return (0);
	return (fd);
}
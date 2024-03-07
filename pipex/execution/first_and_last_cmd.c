/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_and_last_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:10:09 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/07 20:04:52 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// int		first_cmd(t_cmd_info cmd, int file_fd, inout)
// {
// 	int	fd[2];
// 	int	pid;

// 	if (pipe(fd) == -1)
// 		return (0);
// 	pid = fork();
// 	if (pid < 0)
// 		return (0);
// 	if (pid == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		//free
// 		execve(cmd_path, cmd, envp);
// 	}
// }
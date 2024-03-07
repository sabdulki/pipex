/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:20:47 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/07 21:15:42 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd_info	init_cmd_info(char **envp, char *cmd, char inout)
{
	t_cmd_info cmd_info;

	cmd_info = malloc(sizeof(t_cmd_info));
	if (!cmd_info)
		return (0);
	cmd_info->cmd = cmd;
	cmd_info->cmd_path = find_path(cmd, envp);
	if (!cmd_info->cmd_path)
		ft_printf("no such cmd\n"); return (0);
	cmd_info->envp = envp;
	cmd_info->rel = inout;
}

void	free_cmd(t_cmd_info cmd)
{
	free(cmd.cmd_path);
	free(cmd);
}
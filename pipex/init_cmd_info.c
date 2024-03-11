/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:20:47 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/11 20:20:18 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd_info	*init_cmd_info(char **envp, char *cmd, int ac)
{
	t_cmd_info *cmd_info;

	cmd_info = malloc(sizeof(t_cmd_info));
	if (!cmd_info)
		return (NULL);
	cmd_info->cmd = cmd;
	cmd_info->envp = envp;
	cmd_info->cmd_path = find_cmd(cmd, envp);
	if (!cmd_info->cmd_path)
		ft_printf("no such cmd\n"); return (0);
	return (cmd_info);
}

void	free_cmd(t_cmd_info *cmd)
{
	free(cmd->cmd_path);
	free(cmd);
}
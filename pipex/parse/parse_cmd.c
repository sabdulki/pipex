/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:50:27 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/05 22:14:08 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parse_cmd(char *cmd)
{
	int		cmd_len;
	char	*short_cmd;
	int		i;

	cmd_len = ft_cmd_len(cmd);
	if (cmd_len <= 0)
		return (NULL);
	short_cmd = malloc(sizeof(char) * cmd_len + 1);
	if (!short_cmd)
		return (NULL);
	i = 0;
	while(i < cmd_len)
	{
		short_cmd[i] = cmd[i];
		i++;
	}
	short_cmd[i] = '\0';
	return (short_cmd);
}

int		ft_cmd_len(char *cmd)
{
	int	i;
	
	if (!cmd)
		return (-1);
	i = 0;
	while(cmd[i])
	{
		if (cmd[i] == ' ' || cmd[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}
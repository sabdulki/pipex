/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:50:27 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/14 15:02:25 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
		return (0);
	i = 0;
	while(cmd[i])
	{
		if (cmd[i] == ' ')
			return (i);
		i++;
	}
	return (i);
}
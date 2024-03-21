/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:26:28 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/21 16:33:27 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd_info	*add_cmd_to_list(t_cmd_info *cmd, t_cmd_info *head)
{
	t_cmd_info	*current;
	t_cmd_info	*new_cmd;

	// new_cmd = malloc(sizeof(t_cmd_info));
	// if (!new_cmd)
	// 	return (NULL);
	new_cmd = cmd;
	new_cmd->next = NULL;
	if (!head)
	{
		head = new_cmd;
		head->next = NULL;
	}
	else
	{
		current = head; // storing the head, the first cmd;
		while(current->next != NULL)
			current = current->next;
		current->next = new_cmd;
	}
	return (head);
}

int	free_list(t_cmd_info *cmd_list)
{
	t_cmd_info	*current;
	t_cmd_info	*tmp;

	if (!cmd_list)
		return (1);
	current = cmd_list;
	while (current)
	{
		tmp = current->next;
		free_cmd(current);
		current = tmp;
	}
	return (1);
}
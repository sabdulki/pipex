/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:26:28 by sabdulki          #+#    #+#             */
/*   Updated: 2024/03/12 15:13:43 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd_list	*add_cmd_to_list(t_cmd_info *cmd, t_cmd_info *head)
{
	t_cmd_info	*current;
	t_cmd_info	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd_info));
	if (!new_cmd)
		return (0);
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

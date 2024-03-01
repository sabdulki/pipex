/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:18:49 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/04 17:26:36 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(void)
{
	write(1, "Error", 6);
	exit(0);
}

void print_args(char **argv)
{
	int arg = 1;
	printf("The arguments are:\n");
	while(argv[arg])
		printf("%s\n", argv[arg++]);
	printf("---------\n");
}

void print_elements(t_stack* stack)
{
	printf("the elments of stack are:\n");
	t_element *head;
	
	head = stack->top;
	while(head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

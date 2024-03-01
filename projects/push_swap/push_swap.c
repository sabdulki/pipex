/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:55:32 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/04 20:15:01 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parsing(int argc, char **argv, t_stack *stack)
{
	char *str;
	char **future_stack;
	int arg;
	int  num;

	arg = 1;
	str = ft_ex_join(argc, argv, " ");
	future_stack = ft_split(str, ' ');
	
	while(future_stack[arg])
	{
		num = ft_atoi(future_stack[arg]);
		push(stack, num);
		print_elements(stack);
		arg++;
	}
	
}

t_stack *make_base_for_stack()
{
	t_stack *stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	return (stack);
}

void	push(t_stack* stack, int num)
{
	t_element *newNum;
	newNum = malloc(sizeof(t_element));
	newNum->data = num;
	newNum->next = stack->top;
    stack->top = newNum;
}

void check_dups(t_stack *stack)
{
	t_element *tmp;
	t_element *tmp2;

	tmp = stack->top;
	while(tmp)
	{
		tmp2 = tmp->next;
		while(tmp2)
		{
			if (tmp->data == tmp2->data)
				ft_error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

t_stack *preparation(int argc, char **argv)
{
	t_stack *stack; 
	//print_args(argv);
	stack = make_base_for_stack();
	parsing(argc, argv, stack);
	check_dups(stack);
}


int main (int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	
	// if (argc == 2)
		// call function

	t_stack *a; 
	int min;
	
	a = preparation(argc, argv);
	min = find_min(a);
}
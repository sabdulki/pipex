/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:55:35 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/04 18:39:08 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_element{
	struct	s_element *next;
	int		data;
}	t_element;

typedef struct s_stack{
	t_element *top;
}	t_stack;
   
void parsing(int argc, char **argv, t_stack *stack);
void print_args(char **argv);
void ft_error(void);
char	*ft_ex_join(int size, char **strs, char *sep);
void print_elements(t_stack* stack);
void	push(t_stack* stack, int num);
int find_min(t_stack* stack);


//build
#endif 
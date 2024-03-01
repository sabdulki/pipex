# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 14:55:30 by sabdulki          #+#    #+#              #
#    Updated: 2023/10/04 18:46:32 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c ex_join.c utils.c start_sorting.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && make && make bonus
	$(CC) $(OBJS) $(CFLAGS) libft/libft.a -o $(NAME)

clean : 
	rm -f push_swap $(OBJS)
	cd libft && make clean

fclean : clean
	rm -f $(NAME)
	cd libft && make fclean

re : fclean all
	cd libft && make fclean && make all

.PHONY : all clean fclean re bonus

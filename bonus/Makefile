# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 15:33:26 by sabdulki          #+#    #+#              #
#    Updated: 2024/03/25 21:31:55 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	pipex.c  \
		find_command.c  \
		cmd_list.c  \
		init_cmd_info.c  \
		execute_cmd.c \
		create_pipes.c \
		parsing.c \
		here_doc.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
#  -fsanitize=address -g3

NAME = pipex

$(NAME): $(OBJS)
	cd ft_printf && make
	cd libft && make
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

all: $(NAME)

clean : 
	rm -f pipex $(OBJS)
	cd libft && make clean
	cd ft_printf && make clean

fclean : clean
	rm -f $(NAME)
	cd libft && make fclean
	cd ft_printf && make fclean

re : fclean all
	cd libft && make fclean && make all
	cd ft_printf && make fclean && make all

.PHONY : all clean fclean re
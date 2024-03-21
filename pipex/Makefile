# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 15:33:26 by sabdulki          #+#    #+#              #
#    Updated: 2024/03/21 16:33:57 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_P = ./parse/check_infile.c \
		./parse/parse_cmd.c \
		./parse/parse_path.c \

SRC = 	pipex.c  \
		find_command.c  \
		cmd_list.c  \
		init_cmd_info.c  \
		execute_cmd.c \
		create_pipes.c \

SRCS = $(SRC) $(SRC_P)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
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

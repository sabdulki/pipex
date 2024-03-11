# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 15:33:26 by sabdulki          #+#    #+#              #
#    Updated: 2024/03/11 18:15:40 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_P = ./parse/check_infile.c \
		./parse/parse_cmd.c \
		./parse/parse_path.c \

SRC_E_C = ./execution/execute_cmd.c \

SRC = pipex.c find_command.c init_cmd_info.c

SRCS = $(SRC) $(SRC_P) $(SRC_E_C)
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

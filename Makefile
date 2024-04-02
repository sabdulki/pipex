# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 15:33:26 by sabdulki          #+#    #+#              #
#    Updated: 2024/03/27 17:22:01 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  		./src/find_command.c \
				./src/cmd_list.c \
				./src/parsing.c \
				./src/execute_cmd.c

PIPEX_SRCS = 	./mandatory/pipex.c  \
				./mandatory/init_cmd_info.c  \
				./mandatory/create_pipes.c \

BONUS_SRCS =	./bonus/get_next_line/get_next_line.c \
				./bonus/get_next_line/get_next_line_utils.c \
				./bonus/here_doc.c \
				./bonus/create_pipes.c \
				./bonus/init_cmd_info.c \
				./bonus/pipex.c

OBJS = $(SRCS:.c=.o)

PIPEX_OBJS = $(PIPEX_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
#  -fsanitize=address -g3

NAME = pipex

$(NAME): $(OBJS) $(PIPEX_OBJS)
	cd src/ft_printf && make
	cd src/libft && make
	$(CC) $(CFLAGS) $(OBJS) $(PIPEX_OBJS) src/libft/libft.a src/ft_printf/libftprintf.a -o $(NAME)

all: $(NAME)

bonus : $(OBJS) $(BONUS_OBJS)
	cd src/ft_printf && make
	cd src/libft && make
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) src/libft/libft.a src/ft_printf/libftprintf.a -o $(NAME)

clean : 
	rm -f pipex $(OBJS) $(PIPEX_OBJS) $(BONUS_OBJS)
	cd src/libft && make clean
	cd src/ft_printf && make clean

fclean : clean
	rm -f $(NAME)
	cd src/libft && make fclean
	cd src/ft_printf && make fclean

re : fclean all

.PHONY : all clean fclean re bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 15:33:26 by sabdulki          #+#    #+#              #
#    Updated: 2024/03/05 21:56:48 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS = $(SRC_S) $(SRC_T) $(SRC)
SRCS = pipex.c parse_path.c parse_cmd.c libft_utils.c check_infile.c find_command.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
#  -fsanitize=address -g3

NAME = pipex

$(NAME): $(OBJS)
	cd libft && make
	cd ft_printf && make
	$(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a libft/libft.a -o $(NAME)

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

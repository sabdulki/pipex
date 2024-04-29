NAME = libft.a

VPATH = .

SRCS = ft_split.c ft_substr.c ft_atoi.c ft_strlcpy.c \
		ft_strlen.c ft_isdigit.c ft_strncmp.c ft_strjoin.c \
		ft_putendl_fd.c

OBJC = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJC)
	ar -r $(NAME) $?

clean : 
	rm -f $(OBJC)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY : all clean fclean re 

                            
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes
LDFLAGS = -lreadline

SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
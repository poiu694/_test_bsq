NAME		= BSQ

SRCS_DIR	= srcs/
INC_DIR		= includes/

SRCS		= $(wildcard $(SRCS_DIR)*.c)
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)


all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

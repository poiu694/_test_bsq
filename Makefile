NAME		= bsq

SRCS_DIR	= srcs/
INC_DIR		= includes/

SRCS		= $(SRCS_DIR)bsq.c \
			  $(SRCS_DIR)ctype.c \
			  $(SRCS_DIR)destructor.c \
			  $(SRCS_DIR)distance_maps.c \
			  $(SRCS_DIR)error.c \
			  $(SRCS_DIR)file_control.c \
			  $(SRCS_DIR)inspection.c \
			  $(SRCS_DIR)inspection2.c \
			  $(SRCS_DIR)main.c \
			  $(SRCS_DIR)maps.c \
			  $(SRCS_DIR)math.c \
			  $(SRCS_DIR)parsing_maps.c \
			  $(SRCS_DIR)string.c \
			  $(SRCS_DIR)set_max_points_idx.c
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

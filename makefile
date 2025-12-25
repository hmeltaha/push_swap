CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -Ilibft
SRCS	= main.c radix.c stack.c stack_util.c operation.c utils.c
OBJS	= $(SRCS:.c=.o)
NAME	= push_swap


all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	make clean -C libft
	rm -f $(OBJS)
	@echo "🧹 Object files removed."

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	@echo "🗑️ Executable removed//fully cleaned."

re: fclean all

.PHONY: all clean fclean re

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -g
NAME	=	push_swap
LIBFT	= 	libft/libft.a
SRCS	=	main.c \
		swap.c \
		push.c \
		rotate.c \
		print_stack.c \
		get_index.c \
		push_swap.c \
		push_swap_six.c \
		push_swap_over_six.c \
		list_utils.c \
		utils.c\
		check_arg.c
OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make fclean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

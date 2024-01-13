CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft
SRCS = push_swap.c # operators/sa.c operators/sb.c operators/ss.c operators/pa.c operators/pb.c operators/ra.c operators/rb.c operators/rr.c operators/rra.c operators/rrb.c operators/rrr.c operators/ft_swap.c operators/ft_push.c operators/ft_rotate.c operators/ft_reverse_rotate.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT_NAME = libft/libft.a

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	@make -s -C libft all

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -s -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -s -C libft fclean

re: fclean all
	@make -s -C libft re

.PHONY: all clean fclean re
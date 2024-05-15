CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft
SRCS = push_swap.c src/ft_sort.c src/ft_sort_small.c src/ft_sort_big.c src/ft_utils.c operations/ft_swap.c operations/ft_reverse_rotate.c operations/ft_rotate.c operations/ft_push.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT_NAME = libft/libft.a
TEST = test
test_src = test.c operations/ft_swap.c operations/ft_reverse_rotate.c operations/ft_rotate.c operations/ft_push.c

all: $(LIBFT_NAME) $(NAME)

test: $(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(test_src) $(LIBS) -o $(TEST)

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

retest: fclean test
	@make -s -C libft re
.PHONY: all clean fclean re
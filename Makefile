CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft
SRCS = push_swap.c src/ft_parsing.c src/ft_sort.c src/ft_sort_small.c src/ft_sort_big.c src/ft_utils.c src/ft_stack_a.c src/ft_stack_b.c operations/ft_swap.c operations/ft_reverse_rotate.c operations/ft_rotate.c operations/ft_push.c src/ft_free_all.c
SRC_BONUS = bonus/checker.c bonus/checker_utils.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c \
			src/ft_free_all.c src/ft_parsing.c src/ft_utils.c  operations/ft_swap.c operations/ft_reverse_rotate.c operations/ft_rotate.c operations/ft_push.c 
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
NAME = push_swap
LIBFT_NAME = libft/libft.a

all: $(LIBFT_NAME) $(NAME)

bonus: $(LIBFT_NAME) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBS) -o checker

$(LIBFT_NAME):
	@make -s -C libft all

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@make -s -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	@make -s -C libft fclean

re: fclean all
	@make -s -C libft re

.PHONY: all clean fclean re bonus
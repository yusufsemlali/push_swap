SRCS = ft_atoi.c  ft_bzero.c  ft_calloc.c  ft_isdigit.c  ft_itoa.c  ft_lstadd_back.c  ft_lstadd_front.c   ft_lstlast.c  ft_lstnew.c  ft_lstsize.c  ft_memset.c
CFLAGS = -Wall -Wextra -Werror 
NAME = libft.a
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@ar -rc $(NAME) $(OBJS)

%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
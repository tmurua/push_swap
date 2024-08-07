NAME	=	push_swap
LIB		=	$(LIBDIR)libft.a
LIBDIR	=	./libft/

CC		=	cc
FLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c			utils_free.c	utils_args.c	utils_stack.c	utils_check.c\
			pick_sort.c		sort_small.c	sort_big.c\
			ops_push.c		ops_rotate.c	ops_reverse_rotate.c		ops_swap.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(OBJS) $(LIB)
	$(CC) -g $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -g $(CFLAGS) -I$(LIBDIR) -I . -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re

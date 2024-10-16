NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./libft/libft.a

SRC =	main.c			input_handler.c		input_validation.c	\
		initialize_and_fill_stacks.c	\
		sorting_operation_swap.c			sorting_operation_rotate.c	\
		sorting_operation_reverse_rotate.c	sorting_operation_push.c \
		chunk_sort_algorithm.c				small_stack_sorting_algorithms.c \
		ranks_and_positions_of_nodes.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft --no-print-directory
	echo "libft compiled"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	echo "$(NAME) generated"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft --no-print-directory
	rm -f $(OBJ)
	echo "object files deleted"

fclean: clean
	make fclean -C ./libft --no-print-directory
	rm -f $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re

.SILENT:

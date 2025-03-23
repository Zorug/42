# Name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = 	main.c ft_printf.c utils1.c utils2.c utils3.c \
		fts_push.c fts_rev_rotate.c fts_rotate.c fts_swap.c

# Libft folder and source files
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Object files for ft_printf and libft
OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# Default target
all: $(LIBFT) $(NAME)

# Create the output
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compile libft.a
$(LIBFT):
	make -C $(LIBFT_DIR)

# Rule to compile C files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)  # Limpa a libft também

# Clean object files and the library
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)  # Limpa a libft também

# Rebuild everything
re: fclean all

# Mark targets as not files
.PHONY: all clean fclean re
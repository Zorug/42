# Name
NAME = pipex

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Sources
SRCS = 	main.c #utils1.c utils2.c utils3.c utils4.c\

# Full paths
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))


# Main rule
all: $(LIBFT) $(NAME)

# Compile
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

# Rule to compile .c inside obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create folder obj/ if needed
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)


# Clean object files
clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)  # Limpa a libft também

# Clean object files and the library
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)  # Limpa a libft também

# Rebuild everything
re: fclean all

# Mark targets as not files
.PHONY: all clean fclean re
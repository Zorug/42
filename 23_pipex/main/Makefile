# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 22:38:38 by cgross-s          #+#    #+#              #
#    Updated: 2025/04/22 23:11:55 by cgross-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
SRCS = 	main.c error_handling.c ft_split_mod.c ft_split_utils.c get_path.c\
		handle_urandom.c parcing_utils.c pipex_utils.c pipex.c

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
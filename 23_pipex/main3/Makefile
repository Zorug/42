# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 21:07:40 by cgross-s          #+#    #+#              #
#    Updated: 2025/04/25 21:08:14 by cgross-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#CORES
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#COMMANDS
CC	= cc
RM	= rm -rf

#FLAGS
CFLAGS 	= -Werror -Wextra -Wall -g -fsanitize=address
LFLAGS	= -L ./libft -lft

#PATH
INC			= include
HEADERS		= include/pipex.h libft/libft.h
SRCS		= srcs
LIBFT_PATH	= libft
OBJ			= objs

#FILES
NAME		= pipex
SRC_FILES	= pipex.c pipex_utils.c get_path.c error_handling.c handle_urandom.c ft_split_mod.c main.c ft_split_utils.c parsing_utils.c
OBJ_FILES	= $(SRC_FILES:%.c=%.o)
TARGET		= $(addprefix $(OBJ)/, $(OBJ_FILES))

#RULES
all: $(NAME)

$(NAME): $(OBJ) $(TARGET) $(HEADERS)
	@ echo "Make $(MAGENTA)libft$(RESET):"
	make -C $(LIBFT_PATH)
	@ echo "Compiling $(GREEN)$(NAME)$(RESET):"
	$(CC) $(CFLAGS) $(TARGET) $(LFLAGS) -o $(NAME)

$(OBJ)/%.o : $(SRCS)/%.c
	@ $(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(OBJ):
	@ mkdir -p $(OBJ)

clean:
	@ echo "Removing $(RED)objs$(RESET)..."
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)
	

fclean: clean
	$(RM) $(OBJS) $(NAME)
	make fclean -C $(LIBFT_PATH)
	@ echo "...and $(RED)$(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean

# .SILENT:
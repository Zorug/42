# CORES
RESET	= \033[0m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
MAGENTA	= \033[1;35m

# COMMANDS
CC	= cc
RM	= rm -rf

# FLAGS
CFLAGS 	= -Werror -Wextra -Wall -g -fsanitize=address

# PATHS
INC		= include
SRCS	= philo
OBJ		= objs

# FILES
NAME		= philo
SRC_FILES	= main.c
OBJ_FILES	= $(SRC_FILES:%.c=%.o)
TARGET		= $(addprefix $(OBJ)/, $(OBJ_FILES))

# RULES
all: $(NAME)

$(NAME): $(OBJ) $(TARGET)
	@ echo "Compiling $(GREEN)$(NAME)$(RESET):"
	$(CC) $(CFLAGS) $(TARGET) -o $(NAME)

$(OBJ)/%.o : $(SRCS)/%.c
	@ $(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(OBJ):
	@ mkdir -p $(OBJ)

clean:
	@ echo "Removing $(RED)objs$(RESET)..."
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@ echo "...and $(RED)$(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
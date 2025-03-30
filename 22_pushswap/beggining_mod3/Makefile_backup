# Name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = main.c ft_printf.c # Add other ft_printf source files here

# Libft folder and source files
LIBFT_DIR = libft
#LIBFT_SRCS = $(addprefix $(LIBFT_DIR)/, ft_atoi.c ft_isprint.c ft_putchar_fd.c \
#		ft_striteri.c ft_strnstr.c ft_putnbr.c ft_putnbr_base.c ft_putptr.c \
#		ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
#		ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
#		ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
#		ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
#		ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
#		ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c ft_putstr.c \
#		ft_putchar.c)
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
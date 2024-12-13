# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 13:24:41 by cgross-s          #+#    #+#              #
#    Updated: 2024/11/07 13:24:42 by cgross-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the ft_printf library
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files for ft_printf
SRCS = ft_printf.c print_char.c print_str.c #ft_printf_utils.c  # Add other ft_printf source files here

# Libft folder and source files
LIBFT_DIR = libft
LIBFT_SRCS = $(addprefix $(LIBFT_DIR)/, ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
		ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
		ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
		ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
		ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
		ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
		ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c)

# Object files for ft_printf and libft
OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# Default target
all: $(NAME)

# Create the ft_printf library
$(NAME): $(OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

# Rule to compile C files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Mark targets as not files
.PHONY: all clean fclean re
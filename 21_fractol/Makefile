NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Lminilibx-linux -lmlx -lXext -lX11 -lm # All library flags here

SRCS = complex_plane.c fromzero.c utils.c libft/ft_printf.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_putnbr.c libft/ft_putptr.c libft/ft_putnbr_unsigned.c libft/ft_putnbr_base.c libft/ft_strlen.c # All source files, including ft_strlen.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
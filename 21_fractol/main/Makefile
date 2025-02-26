# Nome do executável
NAME = fractol

# Compilador
CC = cc

# Flags do compilador
CFLAGS = -Wall -Wextra -Werror

# Bibliotecas necessárias
MLX_LIB = -L minilibx-linux -lmlx -lXext -lX11 -lm

# Arquivos-fonte
SRC = fractol.c complex_plane.c utils.c

# Arquivos-objeto (os arquivos .o gerados a partir dos .c)
OBJ = $(SRC:.c=.o)

# Regra padrão: compilar tudo
all: $(NAME)

# Como compilar o executável
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) -o $(NAME)

# Como compilar arquivos .c em .o
%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos objeto e executável
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Recompila tudo do zero
re: fclean all

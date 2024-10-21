# Definindo variáveis
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)
NAME = meu_programa # OBRIGATÓRIO

# Regra principal
$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all:  # OBRIGATÓRIO

# Regra para criar os arquivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos objeto (.o)
clean: # OBRIGATÓRIO
	rm -f $(OBJS)

# Limpa os arquivos objetos e o executável
fclean: clean # OBRIGATÓRIO
	rm -f $(NAME)

# Reconstrói tudo do zero
re: fclean $(NAME) # OBRIGATÓRIO

.PHONY: clean fclean re
# Definindo variáveis
CC = cc								# Compilador
CFLAGS = -Wall -Wextra -Werror		# Flags de compilação
SRCS = main.c utils.c				# Arquivos .c do projeto
OBJS = $(SRCS:.c=.o)				# Converte arquivos .c para .o
NAME = meu_programa # OBRIGATÓRIO	# Nome do executável

# Regra principal: compila o executável
all: $(NAME)  # OBRIGATÓRIO

# Regra principal
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

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
re: fclean all # OBRIGATÓRIO

.PHONY: all clean fclean re
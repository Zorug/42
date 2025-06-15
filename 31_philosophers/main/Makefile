NAME = philo
FLAGS = -Werror -Wextra -Wall -g #-fsanitize=thread
SRCS = main.c checkers.c destroy.c init.c philo.c \
	routine.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) philo.h
	cc $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
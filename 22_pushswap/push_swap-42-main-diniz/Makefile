# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 19:31:29 by abessa-m          #+#    #+#              #
#    Updated: 2025/02/05 10:47:19 by abessa-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################################## Test  #
#test: re
#	@echo -n "$(YELLOW)" ; \
#	norminette *.c | grep -v -E \
#	"Comment is invalid in this scope" \
#	| grep Error ; echo -n "$(COR)" ; \
#	valgrind --quiet -s --leak-check=full \
#	./push_swap -43 -703 257 -60 -251 769 -115 893 89 61 737 -402 -390 773 -250 586 -247 578 88 -652 254 -18 -498 -594 -338 950 533 -259 -656 -494 426 -668 -670 104 651 748 -282 226 -806 -987 465 688 -570 434 758 -188 -27 -886 -449 527 237 614 353 -417 81 -858 -678 -192 -805 561 44 -171 915 440 323 429 176 -444 804 -982 420 -716 99 510 -203 -193 816 85 -804 -744 616 -521 -921 453 751 -1000 -542 990 -234 -761 828 58 460 406 583 -625 12 -596 -411 428 ; \
#	echo "$(GRAY)Return value: $$?$(COR)" ; \
#	$(RM) *.o *.gch ; \
#	make --no-print-directory -C libft/ clean 

#	valgrind --quiet -s --leak-check=full \
#	./push_swap "0 2 1" ; \
#	echo "$(GRAY)Return value: $$?$(COR)" ; \

NAME		:= push_swap
NAME-BONUS	:= checker
LIBFT		:= libft.a
#################################################################### Compiler  #
CC			:= cc
CFLAGS		:= -g  -Wall -Wextra -Werror
########################################################## Intermidiate steps  #
RM			:= rm -f
AR			:= ar rcs
######################################################### Objects and Headers  #
HEADERS		= push_swap.h
SRCS		= \
	push_swap.c \
	ps-initialize.c \
	ps-utils-stack.c ps-utils-order.c ps-utils-median.c \
	ps-op.c ps-op-swap.c ps-op-push.c ps-op-rotate.c ps-op-reverse.c \
	ps-check.c \
	ps-algo-small.c \
	ps-algo-turk.c \
	ps-algo-buble.c \
	ps-algo-quick.c ps-algo-quick-eco.c ps-algo-quick-move.c \
	ps-algo-quick-rotate.c 
	
OBJS		= $(SRCS:.c=.o)

SRCS-BONUS		= \
	b-checker_bonus.c b-checker-initialize_bonus.c b-utils-stack_bonus.c \
	b-op-push_bonus.c b-op-reverse_bonus.c \
	b-op-rotate_bonus.c b-op-swap_bonus.c 

OBJS-BONUS		= $(SRCS-BONUS:.c=.o)
##################################################################### Targets  #
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME) \
	&& echo "$(GRAY)Compiled:$(COR) $(SRCS)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ \

$(LIBFT):
	@make --no-print-directory -C ./libft/ 

bonus: $(OBJS-BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS-BONUS) $(LIBFT) -o $(NAME-BONUS) \
	&& echo "$(GRAY)Compiled:$(COR) $(SRCS-BONUS)"

clean:
	@$(RM) *.o *.gch ; \
	make --no-print-directory -C libft/ clean 

fclean: clean
	@make --no-print-directory -C libft/ fclean \
	&& $(RM) $(NAME) $(NAME-BONUS)

re: fclean all	
	@echo "$(GRAY)redone$(COR)"
####################################################################### Colors #
COR = \033[0m# COlor Remove
PURPLE = \033[1;35m# purple
GRAY = \033[1;90m# gray
YELLOW = \033[1;93m# yellow

